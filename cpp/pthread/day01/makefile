test_pthread:test_pthread.c
	gcc $^ -o $@  -lpthread  -g

pthread_exit:pthread_exit.c	
	gcc $^  -o $@  -lpthread

pthread_cancel:pthread_cancel.c
	gcc $^ -o $@ -lpthread 
pthread_join:pthread_join.c
	gcc $^ -o  $@ -lpthread
pthread_detach:pthread_detach.c
	gcc $^ -o $@  -lpthread

pthread_global:pthread_global.c
	gcc $^ -o $@ -lpthread

pthread_stack:pthread_stack.c
	gcc $^ -o $@ -lpthread

pthread_heap:pthread_heap.c
	gcc $^ -o $@ -lpthread

abort:abort.c
	gcc $^ -o $@ -lpthread

time:time.c
	gcc $^ -o $@   -std=c99  -lpthread 
