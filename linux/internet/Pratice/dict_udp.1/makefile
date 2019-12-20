.PHONY:all

all:server  client

server:udp_server.hpp  udp_socket.hpp server.cc 
	g++ server.cc -o server -g  -std=c++11

client:udp_client.hpp udp_socket.hpp client.cc 
	g++ client.cc -o client -g -std=c++11

.PHONY:clean 

clean:
	rm client server
