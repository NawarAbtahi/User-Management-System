# Compiler
CC = gcc

# Source and output
SRC = main.c
OUT = main

# Build rule
all: $(OUT)

$(OUT): $(SRC)
	$(CC) -o $(OUT) $(SRC)

# Run the compiled program
run: $(OUT)
	./$(OUT)

# Clean up
clean:
	rm -f $(OUT)

