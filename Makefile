CC = gcc
SRCS = main.c
FILES = $(addprefix src/, $(SRCS))
OBJS = $(FILES:.c=.o)
LIBS = 
CFLAGS =  

%.o: %.c $(FILES)
	$(CC) -c -o $@ $< $(CFLAGS) -fPIC 

build: $(OBJS)
	$(CC) $(OBJS) $(LIBS) --shared -o ./../build/filter_sepia.so

dist: build
		rm $(OBJS)

clean:
		rm $(OBJS)
