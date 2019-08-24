thread_mutex:thread_mutex.c
	gcc $^ -o $@  -std=c99 -lpthread 

thread_death:thread_death.c
	 gcc $^ -o $@  -std=c99 -lpthread

thread_cond:thread_cond.c
	gcc $^ -o $@ -lpthread

ModifyCount:ModifyCount.c
	gcc $^  -o  $@ -std=c99  -lpthread

time:time.c
	gcc $^ -o $@ -std=c99  

thread_time:thread_time.c
	gcc $^ -o $@  -std=c99  -lpthread
