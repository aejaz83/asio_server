/*
 * Author: Aehjaj Ahmed P
 * Date: 26-June-2019
*/ 
#include <iostream>
#include <boost/asio.hpp>
#include "tcp_server.hpp"

int main(int argc, char const *argv[])
{
	try{
		if(argc != 2){
			std::cerr << "Usage: tcp_server <port>\n";
			return 1;
		}
		std::stringstream ss(argv[1]);
		int port;
		if( ss >> port){
			std::cout << "port number of the server: " << port << std::endl;
		}else{
			std::cerr << "Invalid port specified, port is not an integer\n";
			return 2;
		}
		boost::asio::io_context io_context;
		Tcp_Server server(io_context, port);
		io_context.run();

	} catch (std::exception& ex){
		std::cerr << "Exception in main: " << ex.what() << std::endl;
	}
	return 0;
}