CC = gcc 
CFLAGS = -Wall -Wextra -I include 

SRCS = main.c src\datos.c src\nodosimple.c
INCLUDES = $(SRCS: .c=.h)
OBJS = $(SRCS: .c=.o)

all = main

main: $(OBJS)
	$(CC) $(CFLAGS) -O main

main.o: $(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) -c main.c -o main.o

nodosimple.o: $(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

datos.o: $(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f main $(OBJS)


