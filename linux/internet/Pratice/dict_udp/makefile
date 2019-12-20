.PHONY:all
all:dict_server dict_client

dict_client:udp_client.hpp  udp_socket.hpp dict_client.cc
	g++ dict_client.cc -o dict_client -g -std=c++11

dict_server:udp_socket.hpp udp_server.hpp  dict_server.cc 
	g++ dict_server.cc -o dict_server  -g  -std=c++11


.PHONY:clean

clean:
	rm dict_client   dict_server
