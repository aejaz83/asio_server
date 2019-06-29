CC=g++
CPPFLAGS=-I/home/aehjaj/boost_1_70_0 -std=c++11
DEPS = tcp_server.hpp tcp_session.hpp 
OBJ = tcp_server.o tcp_session.o server_main.o
LINKERFLAGS = -pthread
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CPPFLAGS)

tcp_server: $(OBJ)
	$(CC) -o $@ $^ $(LINKERFLAGS)
#tcp_server: tcp_server.o tcp_session.o server_main.o
#	g++ -pthread -o tcp_server tcp_server.o tcp_session.o server_main.o


#server_main.o: server_main.cpp
#	g++ -std=c++11 -I /home/aehjaj/boost_1_70_0 -c server_main.cpp

#tcp_server.o: tcp_server.cpp tcp_server.hpp
#	g++ -std=c++11 -I /home/aehjaj/boost_1_70_0 -c tcp_server.cpp

#tcp_session.o: tcp_session.cpp tcp_session.hpp
#	g++ -std=c++11 -I /home/aehjaj/boost_1_70_0 -c tcp_session.cpp


clean:
	rm -rf *.o tcp_server		