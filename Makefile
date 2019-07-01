CC=g++
CPPFLAGS=-I/home/aehjaj/boost_1_70_0 -std=c++11
DEPS = tcp_server.hpp tcp_session.hpp tcp_client.hpp
OBJ = tcp_server.o tcp_session.o server_main.o
LINKERFLAGS = -pthread
OBJ_CLIENT = tcp_client.o client_main.o
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CPPFLAGS)

all: tcp_client tcp_server	

tcp_server: $(OBJ)
	$(CC) -o $@ $^ $(LINKERFLAGS)

tcp_client: $(OBJ_CLIENT)
	$(CC) -o $@ $^ $(LINKERFLAGS)



clean:
	rm -rf *.o tcp_server tcp_client		