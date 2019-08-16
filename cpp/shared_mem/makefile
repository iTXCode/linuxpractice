.PHONY:all
all:reader writer 
create:create.c
	gcc $^ -o $@
reader:reader.c
	gcc $^ -o $@
writer:writer.c
	gcc $^ -o $@
.PHONY:clean
clean:
	rm reader writer  
