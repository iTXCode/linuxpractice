reader_wirte:reader_wirte.cc 
	g++ $^  -o $@ -lpthread

rwlock:rwlock.cc 
	g++ $^ -o  $@  -lpthread

thread:thread.cc 
	g++ $^  -o $@  -lpthread  -std=c++11

atomic:atomic.cc 
	g++ $^ -o  $@  -lpthread  -std=c++11
test:test.c
	gcc test.c  -o test  -std=c99 
