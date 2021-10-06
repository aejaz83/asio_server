UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
  CC=g++
endif
ifeq ($(UNAME_S),Darwin)
  CC=clang++
endif

CPPFLAGS=-I/include_path_for_boost/boost_1_70_0 -std=c++14 -Wall

all: tcp_client tcp_server	

tcp_server:
	$(MAKE) -C server CC="$(CC)" CPPFLAGS="$(CPPFLAGS)"

tcp_client:
	$(MAKE) -C client CC="$(CC)" CPPFLAGS="$(CPPFLAGS)"

clean:
	rm -rf client/*.o client/tcp_client		
	rm -rf server/*.o server/tcp_server		
