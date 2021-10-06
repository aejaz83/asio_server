/*
 * Author: Aehjaj Ahmed P
 * Date: 27-June-2019
*/ 

#ifndef TCPSESSION_H
#define TCPSESSION_H
#include <array>
#include <memory>

// this class represents a unique client session
// order of calls 
// accept ---> read ---> write
// extend lifetime of the client as it uses async calls
// enable_shared_from_this is used.
class Tcp_Session : public std::enable_shared_from_this<Tcp_Session> {
public:
  Tcp_Session( boost::asio::io_context& );
	boost::asio::ip::tcp::socket& get_socket();
	//receive data from client
	void wait_for_receive();
private:
	void start_send();
	boost::asio::ip::tcp::socket socket_;
	std::array<char, 2048> receive_buffer_;
	std::string response_ = "OK";
	
};
#endif


