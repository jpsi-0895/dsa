# Makefile for CircularLinkedListProject

CXX = g++
CXXFLAGS = -std=c++11 -Wall
OBJDIR = obj
BINDIR = bin
SRCDIR = src
INCDIR = include

SRC_FILES = $(SRCDIR)/CircularLinkedList.cpp $(SRCDIR)/main.cpp
OBJ_FILES = $(SRC_FILES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
EXEC = $(BINDIR)/circular_linked_list

# Create output directories if they do not exist
$(shell mkdir -p $(OBJDIR) $(BINDIR))

# Default target to build the project
all: $(EXEC)

# Link object files to create the final executable
$(EXEC): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ_FILES)

# Compile source files to object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# Clean up the object files and the executable
clean:
	rm -rf $(OBJDIR)/*.o $(EXEC)
