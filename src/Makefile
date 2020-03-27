CC=g++-9
CFLAGS=-std=c++11
LDFLAGS=-ldl -lm -I "include" -I "/usr/local/include" `pkg-config --cflags glfw3 assimp` `pkg-config --static --libs glfw3 assimp`
PROJ=MeshViewer

all:
	$(CC) $(CFLAGS) $(LDFLAGS) main.cpp glad.c -o $(PROJ) 