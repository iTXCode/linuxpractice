.PHONY:all

all::server client

server:server.cc tcp_server.hpp tcp_socket.hpp 
	g++ server.cc -o server -g -std=c++11

client:client.cc tcp_client.hpp tcp_socket.hpp 
	g++ client.cc -o client -g -std=c++11

.PHONY:clean 
	
clean:
	rm client server 
