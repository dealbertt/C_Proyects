# Compiler
CXX = g++  # C++ compiler
CC = gcc   # C compiler
CXXFLAGS = -Wall -std=c++17 $(shell pkg-config --cflags sdl2)
CFLAGS = -Wall $(shell pkg-config --cflags sdl2)  # C compiler flags
LDFLAGS = $(shell pkg-config --libs sdl2)  # SDL2 linking flags

# Source and Object Files
SRC = main.cpp pad.cpp ball.cpp graphics.c game.cpp config.cpp timer.cpp # C++ and C sources
OBJ = $(SRC:.cpp=.o)  # Convert .cpp to .o
OBJ := $(OBJ:.c=.o)   # Convert .c to .o

# Target executable
TARGET = Pong

# Build the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

# Rule to compile C++ source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile C source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the build files (DOES NOT DELETE SOURCE FILES)
clean:
	rm -f $(OBJ) 

