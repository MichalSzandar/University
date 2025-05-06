# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Directories
SRC_DIR = .
BIN_DIR = .

# Find all .cpp files
CPP_FILES = $(shell find $(SRC_DIR) -name "*.cpp")

# Generate corresponding executable names
EXECUTABLES = $(CPP_FILES:%.cpp=%)

# Default target
all: $(EXECUTABLES)

# Rule to compile .cpp files into executables
%: %.cpp
	@$(CXX) $(CXXFLAGS) -o $@ $<

# Clean up executables
clean:
	@rm -f $(EXECUTABLES)

# Phony targets
.PHONY: all clean