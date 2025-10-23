# Compiler and flags
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Iinclude

# Source files for main demo
SRC = main.c src/core/matrix.c
OBJ = $(SRC:.c=.o)
TARGET = mlc_demo

# Source files for tests
TEST_SRC = tests/test_linear_regression.c src/models/linear_regression.c src/core/matrix.c src/core/activations.c
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_TARGET = test_linear_regression

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