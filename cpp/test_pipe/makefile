.PHONY:all
all:reader  writer
#伪目标

reader:reader.c
	gcc $^ -o $@

writer:writer.c
	gcc $^ -o $@

.PHONY:clean
clean:
	rm reader  writer
