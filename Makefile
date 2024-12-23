# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -g
INCLUDE = -Iinclude

# Directories
SRC_DIR = src
BUILD_DIR = build
TARGET = shell

# Source and Object Files
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

# Build Rules
all: $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR) # Ensure the build directory exists
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)