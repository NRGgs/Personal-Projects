# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -g

# Source files and headers
SRCS = check.c linkedlist.c main.c myfunctions.c options.c read.c write.c error.c sort.c
HEADERS = todo.h
OBJS = $(SRCS:.c=.o)

# Output executable
TARGET = todolist

# Default target
all: $(TARGET)

# Rule to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .c files into .o files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
