.PHONY:all
all:calc_server  calc_client

calc_server:calc_server.cc tcp_thread_server.hpp tcp_socket.hpp tcp_client.hpp
	g++ calc_server.cc  -o  calc_server  -lpthread   -ljsoncpp  -std=c++11

calc_client:calc_client.cc tcp_client.hpp   tcp_thread_server.hpp 
	g++ calc_client.cc  -o calc_client  -lpthread   -ljsoncpp



# 在编译时不加上动态库(-ljsoncpp), 会提示只有声明(.cc文件中的内容)没看到定义(动态库中的内容)
# -l 表示链接到某个库,而jsoncpp是要连接的库名
