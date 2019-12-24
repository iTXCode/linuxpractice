FLAG=-std=c++11 -lpthread 

.PHONY:all


all:dict_server dict_client

dict_server:dict_server.cc tcp_socket.hpp tcp_thread_server.hpp 
	g++ dict_server.cc -o dict_server  $(FLAG)

dict_client:dict_client.cc tcp_client.hpp tcp_socket.hpp 
	g++ dict_client.cc  -o dict_client  $(FLAG)

.PHONY:clean

clean:
	rm dict_client dict_server 
