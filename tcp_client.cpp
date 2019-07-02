/*
 * Author: Aehjaj Ahmed P
 * Date: 1-July-2019
*/
#include <iostream>
#include "tcp_client.hpp"

using namespace boost::asio;

Tcp_Client::Tcp_Client(io_context& io_context,
               const ip::tcp::resolver::results_type& endpoints) 
               : io_context_(io_context),
                 socket_(io_context),
                 parser(std::make_unique<CoutParser>()){
    connect(endpoints);
}

void Tcp_Client::connect(const ip::tcp::resolver::results_type& endpoints){
    async_connect(socket_, endpoints,
    [this](const boost::system::error_code& ec, ip::tcp::endpoint){
        if(!ec){
            std::cout << "Connect Successfull\n";
            write();
        }else{
            //if there is an error in connect then close the socket
            std::cerr << "client connection failed: " << ec.message() << std::endl;
            socket_.close();
        }
    });
}

void Tcp_Client::write(){
    async_write(socket_, buffer(write_buf_, 11),
    [this](const boost::system::error_code& ec, std::size_t write_length){
        if(!ec){
            std::cout << "client wrote " << write_length << " bytes successfully\n";
             read();
        }else{
            //if there is an error in connect then close the socket
            std::cerr << "client write failed: " << ec.message() << std::endl;
            socket_.close();
        }
    });

}

void Tcp_Client::read(){
    std::cout << "Inside Tcp_Client::read() \n";
    async_read( socket_, buffer(read_buf_,2),
        [this](const boost::system::error_code& ec, size_t byte_size){
            if (!ec || ec == error::eof) {
               std::cout.write(this->read_buf_.data(), byte_size);
               //parse the data
               parser->parse(read_buf_,byte_size);
               socket_.close();
            } else {
                std::cerr << "Error receiving data from server: " << ec.message() << "\n";
            }
        });

}
