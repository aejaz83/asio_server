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
		boost::asio::io_context io_context;
		Tcp_Server server(io_context,8989);
		io_context.run();

	} catch (std::exception& ex){
		std::cerr << "Exception in main: " << ex.what() << std::endl;
	}
	return 0;
}