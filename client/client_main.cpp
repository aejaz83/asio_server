/*
 * Author: Aehjaj Ahmed P
 * Date: 1-July-2019
*/ 
#include <iostream>
#include <boost/asio.hpp>
#include "tcp_client.hpp"

using boost::asio::ip::tcp;


int main(int argc, char* argv[]){
  try{
      if(argc != 3){
        std::cerr << "Usage: tcp_client <host> <port>\n";
        return -1;
      }
      boost::asio::io_context io_context;
      // boost::asio::io_service::work work(io_context);
      tcp::resolver resolver(io_context);
      auto endpoints = resolver.resolve(argv[1], argv[2]);
      Tcp_Client client(io_context, endpoints);

      io_context.run();
    } catch (std::exception& e){
      std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}