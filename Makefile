CC := gcc
exe := main
obj := main.o queue.o

%.o:%.c
	$(CC) -c $^ -o $@

all:$(obj)
	$(CC) -o $(exe) $(obj)

clean:
	rm *.o

.PHONY: clean
