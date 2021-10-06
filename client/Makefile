DEPS = tcp_client.hpp parser.hpp
OBJ = tcp_client.o client_main.o
LINKERFLAGS = -pthread
%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CPPFLAGS)

all: tcp_client	

tcp_client: $(OBJ)
	$(CC) -o $@ $^ $(LINKERFLAGS)

clean:
	rm -rf *.o tcp_client		
