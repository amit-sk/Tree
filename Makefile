# Compiler and compilation flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Werror -pedantic-errors
CC := gcc
CFLAGS := -Wall -Wextra -Werror -pedantic-errors

# build directory 
BUILDDIR := build

# Executable name
EXEC := main

# Source files
SRC := main.cpp Tree.cpp TreeNode.cpp
HEADERS := Tree.hpp TreeNode.hpp

# Object files (compiled .o files)
OBJ := $(addprefix $(BUILDDIR)/,$(SRC:.cpp=.o))

# Default target: Compile the program
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

# Compile .c files into .o files
$(BUILDDIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILDDIR)/*
