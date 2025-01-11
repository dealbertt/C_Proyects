# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -I.  # Include current directory for header files

LDFLAGS = -lm
# Source and object files
SRC = main.c grayscale.c utils.c ascii.c resize.c
OBJ = $(SRC:.c=.o)
TARGET = image_processor

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

