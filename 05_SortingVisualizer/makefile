CXX = g++  
CC = gcc   
CXXFLAGS = -Wall -Werror -std=c++17 $(shell pkg-config --cflags sdl3) -Iinclude 
LDFLAGS = $(shell pkg-config --libs sdl3)  

SRC_DIR = src
SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/config.cpp  $(SRC_DIR)/algorithm.cpp $(SRC_DIR)/keyboard.cpp

OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)  # Convert .cpp to .o

TARGET = Visual

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)
