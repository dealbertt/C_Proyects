# Compiler
CXX = g++  # C++ compiler
CC = gcc   # C compiler
CXXFLAGS = -Wall -std=c++17 $(shell pkg-config --cflags sdl2)
CFLAGS = -Wall $(shell pkg-config --cflags sdl2)  # C compiler flags
LDFLAGS = $(shell pkg-config --libs sdl2)  # SDL2 linking flags

# Source and Object Files
SRC_DIR = src
SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/pad.cpp $(SRC_DIR)/ball.cpp $(SRC_DIR)/graphics.c $(SRC_DIR)/game.cpp $(SRC_DIR)/config.cpp $(SRC_DIR)/timer.cpp # C++ and C sources
OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)  # Convert .cpp to .o
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)  # Convert .c to .o

# Target executable
TARGET = Pong

# Build the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

# Rule to compile C++ source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile C source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the build files (DOES NOT DELETE SOURCE FILES)
clean:
	rm -f $(OBJ_DIR) $(TARGET)

