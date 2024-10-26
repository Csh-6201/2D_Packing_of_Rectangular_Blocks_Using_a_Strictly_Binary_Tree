# Compiler and flags
CC = gcc
CFLAGS = -O3 -std=c99 -Wall -Wshadow -Wvla -pedantic

# Object files
OBJS = read_tree.o compute_dimensions.o compute_coordinates.o a6.o

# Target executable
a6: $(OBJS)
	$(CC) $(CFLAGS) -o a6 $(OBJS)

# Compilation rules for each object file
read_tree.o: read_tree.c tree.h
	$(CC) $(CFLAGS) -c read_tree.c -o read_tree.o

compute_dimensions.o: compute_dimensions.c tree.h
	$(CC) $(CFLAGS) -c compute_dimensions.c -o compute_dimensions.o

compute_coordinates.o: compute_coordinates.c tree.h
	$(CC) $(CFLAGS) -c compute_coordinates.c -o compute_coordinates.o

a6.o: a6.c tree.h
	$(CC) $(CFLAGS) -c a6.c -o a6.o

# Clean rule
clean:
	rm -f *.o a6
