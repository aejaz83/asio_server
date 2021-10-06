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
            :socket_( io_context ) {}

ip::tcp::socket& Tcp_Session::get_socket(){
  return socket_;
}

void Tcp_Session::wait_for_receive(){
  // here we have async calls , so in order to extend the lifetime 
  // of the object, shared_ptr is used and being captured in the async lambdas like
  // async_read_some and async_write
  auto session_ptr = shared_from_this();
  //ideally we should read the data length (header) first and then rest of the message
  socket_.async_read_some( buffer(receive_buffer_),
        [session_ptr](const boost::system::error_code& ec, size_t byte_size){
          if (!ec || ec == error::eof) {
            std::cout.write(session_ptr->receive_buffer_.data(), byte_size);
            //flush the buffer and add a new line
            //added for proper display of message on standard output
            std::cout << std::endl;
            session_ptr->start_send();
            if(!ec) { session_ptr->wait_for_receive(); }
          } else {
            std::cerr << "Error receiving data from client: " << ec.message() << "\n";
          }

        });
}

void Tcp_Session::start_send(){
  auto session_ptr = shared_from_this();
  //ideally we should write the number of bytes first and then 
  // write rest of data
  async_write (socket_, buffer(response_),
    [session_ptr](const boost::system::error_code& ec, size_t sz){
      if (ec) {
        if (ec == error::eof) {
          session_ptr->socket_.close();
        }

        std::cerr << "Failed to send response to client: " << ec.message() << std::endl;
      }

    }); 

}