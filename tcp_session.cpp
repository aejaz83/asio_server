/*
 * Author: Aehjaj Ahmed P
 * Date: 26-June-2019
*/ 

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "tcp_session.hpp"

using namespace boost::asio;

Tcp_Session::Tcp_Session( boost::asio::io_context& io_context)
            :socket_( io_context ){

}

ip::tcp::socket& Tcp_Session::get_socket(){
    return socket_;
}


void Tcp_Session::wait_for_receive(){
    auto session_ptr = shared_from_this();
    async_read(socket_, buffer(receive_buffer_),
        [session_ptr](const boost::system::error_code& ec, size_t byte_size){
            if(ec) {
                std::cerr << "Error receiving data from client: " << ec.message() << "\n";
            } else {
                session_ptr->start_send();
                //session_ptr->receive_buffer_[byte_size] = "\0";
                std::cout << session_ptr->receive_buffer_.data() << "\n";

                if(!ec) { session_ptr->wait_for_receive(); }
            }
        });
}

void Tcp_Session::start_send(){
    std::string message = "Hellow from Server";
    auto session_ptr = shared_from_this();
    async_write (socket_, buffer(message),
        [session_ptr](const boost::system::error_code& ec, size_t sz){

        }); 

}