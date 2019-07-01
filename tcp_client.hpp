/*
 * Author: Aehjaj Ahmed P
 * Date: 1-July-2019
*/ 
#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include <boost/asio.hpp>
#include <array>
#include <string>

class Tcp_Client{
public:
    Tcp_Client(boost::asio::io_context& io_context,
               const boost::asio::ip::tcp::resolver::results_type& endpoints);

private:
    void connect(const boost::asio::ip::tcp::resolver::results_type& endpoints);
    void read();
    void write();

    boost::asio::io_context& io_context_;
    boost::asio::ip::tcp::socket socket_;
    std::array<char, 2048> read_buf_;
    std::string write_buf_ = "Hello World";
};
#endif