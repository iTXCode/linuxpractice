.PHONY:all   
all: reader write create 
create:create.c myshm.h
	gcc create.c   -o create
	
reader:reader.c myshm.h
	gcc reader.c  -o reader 
 
write:write.c myshm.h
	gcc write.c  -o write
