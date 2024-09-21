# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -g

# Source files and headers
SRCS = bot.c check.c main.c memory.c player.c print.c
HEADERS = tictactoe.h
OBJS = $(SRCS:.c=.o)

# Output executable
TARGET = tictactoe

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
