INCLUDES = -I/usr/local/include

LIBS = -L/usr/local/lib -lglfw  -lGLEW -framework OpenGL

COMMON = ../common/*.cpp

cube : cube.cpp $(COMMON)
	g++ $^ $(INCLUDES) $(LIBS)  -o $@.exe


clean:
	rm -rf *.exe

