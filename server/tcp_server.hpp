/*
 * Author: Aehjaj Ahmed P
 * Date: 26-June-2019
*/ 

#ifndef TCPSERVER_H
#define TCPSERVER_H

//This class waits for an incoming client to connect to it by using acceptor
//when a connection is succesfully established it creates an object of type
//Tcp_Session which successfully handles the connection with the client, then
// it goes back to accept connections, All calls are asynchronous in this class. 
class Tcp_Server {
public:
	Tcp_Server(boost::asio::io_context& io_context, int port);
	//launches an async call to accept connections from server
	void wait_for_connection();

private:
	boost::asio::io_context& context_;
	boost::asio::ip::tcp::acceptor acceptor_;

};
#endif


