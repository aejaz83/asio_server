/*
 * Author: Aehjaj Ahmed P
 * Date: 27-June-2019
*/ 

#ifndef TCPSESSION_H
#define TCPSESSION_H
#include <array>
#include <memory>

class Tcp_Session : public std::enable_shared_from_this<Tcp_Session> {
public:
	Tcp_Session( boost::asio::io_context& );
	boost::asio::ip::tcp::socket& get_socket();
	void wait_for_receive();
private:
	boost::asio::ip::tcp::socket socket_;
	std::array<char, 2048> receive_buffer_;
	
};
#endif


