
CC = gcc
CFLAGS = -Wall -g -s
SRCS = a4.c window.c
OBJS = $(SRCS:.c=.o)
TARGET = a4

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)