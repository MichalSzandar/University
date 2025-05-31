# Compiler and flags
CXX := g++
CXXFLAGS := -g -std=c++17 -Wall -Iinclude

# Directories
ALGODIR := algorithms
INCLUDEDIR := include
GENDIR := inputGenerators
BINDIR := bin

# Create bin directory if not exists
$(shell mkdir -p $(BINDIR))

# Sources and objects
MAIN_SRC := $(ALGODIR)/main.cpp
MAIN_OBJ := $(ALGODIR)/main.o
ALGO_SRCS := $(filter-out $(MAIN_SRC), $(wildcard $(ALGODIR)/*.cpp))
ALGO_OBJS := $(ALGO_SRCS:.cpp=.o)
TARGET := $(BINDIR)/main

GEN_SRCS := $(wildcard $(GENDIR)/*.cpp)
GEN_TARGETS := $(patsubst $(GENDIR)/%.cpp, $(BINDIR)/%, $(GEN_SRCS))

all: $(TARGET) $(GEN_TARGETS)

# Link the main program
$(TARGET): $(ALGO_OBJS) $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files
$(ALGODIR)/%.o: $(ALGODIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile input generators
$(BINDIR)/%: $(GENDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(ALGODIR)/*.o $(TARGET) $(GEN_TARGETS)

.PHONY: all clean
