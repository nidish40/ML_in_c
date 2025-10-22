# Compiler and flags
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Iinclude

# Source files for main demo
SRC = main.c src/core/matrix.c
OBJ = $(SRC:.c=.o)
TARGET = mlc_demo

# Source files for tests
TEST_SRC = tests/test_matrix.c src/core/matrix.c
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_TARGET = test_matrix

# Default build: demo
all: $(TARGET)

# Build demo executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

# Build test executable and run it
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Build test executable
$(TEST_TARGET): $(TEST_OBJ)
	$(CC) $(TEST_OBJ) -o $@

# Clean compiled files
clean:
	rm -f $(OBJ) $(TARGET) $(TEST_OBJ) $(TEST_TARGET)
