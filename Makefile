CXX=g++
CXXFLAGS=-fopenmp -O2 -std=c++17
TARGET=bfs_parallel

all: $(TARGET)

$(TARGET): src/bfs_parallel.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(TARGET)
