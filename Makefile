CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET_DIR = bin
TARGET = $(TARGET_DIR)/app
SRC = src/main.c

# The 'all' rule now depends on the bin directory existing
all: $(TARGET_DIR) $(TARGET)

# Create the bin directory if it doesn't exist
$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

# Compile the app into the bin folder
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -rf $(TARGET_DIR)
