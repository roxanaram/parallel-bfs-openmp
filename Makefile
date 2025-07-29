CC = g++
CFLAGS = -fopenmp -O2

all: bfs

bfs: bfs.cpp
	$(CC) $(CFLAGS) bfs.cpp -o bfs

clean:
	rm -f bfs
