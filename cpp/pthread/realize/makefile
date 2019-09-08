pthread_create:pthread_create.c
	gcc $^  -o $@   -lpthread

pthread_join:pthread_join.c
	gcc $^  -o  $@  -lpthread

pthread_detach:pthread_detach.c
	gcc $^  -o  $@  -lpthread

pthread_exit:pthread_exit.c
	gcc $^  -o  $@  -lpthread

ps_model:ps_model.cc 
	g++ $^ -o $@  -lpthread

ps_model_queue:ps_model_queue.cc
	g++ ps_model_queue.cc -o ps_model_queue   -lpthread
