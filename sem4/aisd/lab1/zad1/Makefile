# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I fifo

# Directories
SRC_DIR = .
OBJ_DIR = obj

# Source files
SRCS = $(SRC_DIR)/main.cpp
OBJS = $(OBJ_DIR)/main.o

# Output binary
TARGET = main

# Create obj directory if not exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Build the executable
$(TARGET): $(OBJ_DIR) $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Compile main.cpp
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp fifo/FIFOQueue.hpp lifo/LIFOStack.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o

# Clean up build files
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: clean run
