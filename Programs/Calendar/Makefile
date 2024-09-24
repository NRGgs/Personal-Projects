# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -g

# Source files and headers
SRCS = check.c input.c main.c memory.c string.c print.c calendar.c
HEADERS = calendar.h
OBJS = $(SRCS:.c=.o)

# Output executable
TARGET = calendar

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
