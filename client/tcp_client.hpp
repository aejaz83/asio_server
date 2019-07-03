/*
 * Author: Aehjaj Ahmed P
 * Date: 1-July-2019
*/ 
#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include <boost/asio.hpp>
#include <array>
#include <memory>
#include <string>
#include "parser.hpp"

//Represents a tcp client connecting to server.
//pattern followed by client
// connect ---> write ---> read
class Tcp_Client{
public:
    Tcp_Client(boost::asio::io_context& io_context,
               const boost::asio::ip::tcp::resolver::results_type& endpoints);
private:
    //connect to server
    void connect(const boost::asio::ip::tcp::resolver::results_type& endpoints);
    //do async receive from server
    void read();
    //do async send to server
    void write();

    boost::asio::io_context& io_context_;
    //the socket to send and receive data
    boost::asio::ip::tcp::socket socket_;
    //parser to parse response from server
    std::unique_ptr<Parser> parser_;
    std::array<char, 256> read_buf_;
    std::string write_buf_ = "Hello World";
};
#endif