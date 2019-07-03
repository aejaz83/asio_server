CC=g++
CPPFLAGS=-I/home/aehjaj/boost_1_70_0 -std=c++14
DEPS = tcp_server.hpp tcp_session.hpp
OBJ = tcp_server.o tcp_session.o server_main.o
LINKERFLAGS = -pthread

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CPPFLAGS)

all: tcp_server	

tcp_server: $(OBJ)
	$(CC) -o $@ $^ $(LINKERFLAGS)

clean:
	rm -rf *.o tcp_server		
