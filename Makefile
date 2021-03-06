CC = mpic++
INCLUDE = header
TARGET = bfs

build: $(TARGET)

bfs: src/main.cpp src/graph.cpp 
	$(CC) $^ -o $@ -I$(INCLUDE)
	cp $(TARGET) bin

run:
	./bfs graphs/test.mtx 0 1 1
#	./bfs <graph_path> <start_vertex> <runs> <method>

clean:
	rm $(TARGET)