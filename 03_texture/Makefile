INCLUDES = -I/usr/local/include

LIBS = -L/usr/local/lib -lglfw  -lGLEW -framework OpenGL

COMMON = ../common/*.cpp

FLAGS = -Wall

2d-texture : 2d-texture.cpp $(COMMON)
	g++ $^ $(INCLUDES) $(LIBS) $(FLAGS) -o $@.exe


clean:
	rm -rf *.exe

