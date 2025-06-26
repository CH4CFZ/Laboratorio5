CC = gcc 
CFLAGS = -Wall -Wextra -Iinclude 

SRCS = main.c src/datos.c src/nodosimple.c
INCLUDES = include/datos.h include/nodosimple.h
OBJS = $(SRCS:.c=.o)

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ 

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

nodosimple.o: $(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

src/datos.o: $(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

   
