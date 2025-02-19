# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -I. # Include current directory for header files

LDFLAGS = -lm -lSDL2
# Source and object files
SRC = main.c graphics.c logic.c levels.c collisions.c	
OBJ = $(SRC:.c=.o)
TARGET = Arcanoid

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ) 

# Phony targets
.PHONY: all clean

