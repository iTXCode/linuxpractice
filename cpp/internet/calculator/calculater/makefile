#定义变量   makefile 中的变量相当于C语言中的宏
FLAG=-std=c++11  -lpthread 
DEPEND=tcp_thread_server.hpp tcp_socket.hpp   tcp_client.hpp

.PHONY:all
all:dict_server  dict_client  calc_client  calc_server 
clac_server:calc_server.cc  $(DEPEND) 
	g++ $^ -o $@  $(FLAG) 

calc_client:calc_client.cc $(DEPEND)
	g++ $^ -o $@  $(FLAG)

dict_server:dict_server.cc tcp_server.hpp  tcp_socket.hpp  tcp_thread_server.hpp  tcp_process_server.hpp 
	g++ dict_server.cc -o dict_server $(FLAG) 

dict_client:dict_client.cc  tcp_client.hpp tcp_socket.hpp  
	g++ dict_client.cc -o dict_client  $(FLAG)


.PHONY:clean 
clean:
	rm dict_client dict_server  clac_server  clac_client 
