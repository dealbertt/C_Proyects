# Compiler
CXX = g++
CXXFLAGS = -Wall -std=c++17 $(shell pkg-config --cflags sdl2)


LDFLAGS = $(shell pkg-config --libs sdl2)

# Source and Object Files
SRC = main.cpp pad.cpp ball.cpp
OBJ = $(SRC:.cpp=.o)
# Target
TARGET = Pong

# Build the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS)  -o $(TARGET) $(OBJ) $(LDFLAGS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean the build files
clean:
	rm -f $(OBJ) 

