# Define the compiler
CC = gcc

# Define the compiler flags
CFLAGS = -Wall -Wextra -O2

# Define the target executable name
TARGET = assignment

# Define the source files
SRC = assignment.c

# Rule to build the target executable
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

test: $(TARGET) test.c
	$(CC) $(CFLAGS) -o test test.c
	./$(TARGET) 5 10
	./test
all: assignment.c 
# Rule to clean up the build files
clean:
	rm -f $(TARGET) test

