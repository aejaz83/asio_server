/*
 * Author: Aehjaj Ahmed P
 * Date: 26-June-2019
*/ 

#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include "tcp_server.hpp"
#include "tcp_session.hpp"

using namespace boost::asio;

Tcp_Server::Tcp_Server(io_context& io_context, int port)
			: context_(io_context),
			  acceptor_(io_context, ip::tcp::endpoint(ip::tcp::v4(),port)){

		wait_for_connection();		
}

void Tcp_Server::wait_for_connection(){
	//auto connection = std::make_shared<Tcp_Session>(acceptor_.get_executor().context());
	auto connection = std::make_shared<Tcp_Session>(context_);
	
	acceptor_.async_accept(connection->get_socket(),
		[this, connection](const boost::system::error_code& ec){
			if(ec){
				std::cerr << "Failed to accept connection: " << ec.message() << std::endl;
			} else {
				std::cout << "Successfully received connection calling connection->wait_for_receive\n" ;
				connection->wait_for_receive();
				wait_for_connection();
			}
		});
}