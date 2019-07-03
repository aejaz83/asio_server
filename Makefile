all: tcp_client tcp_server	

tcp_server:
	$(MAKE) -C server

tcp_client:
	$(MAKE) -C client


clean:
	rm -rf client/*.o client/tcp_client		
	rm -rf server/*.o server/tcp_server		
