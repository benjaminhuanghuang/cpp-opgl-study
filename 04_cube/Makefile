INCLUDES = -I/usr/local/include -I../common

LIBS = -L/usr/local/lib -lglfw  -lGLEW -framework OpenGL

COMMON = ../common/*.cpp

cube : cube.cpp $(COMMON)
	g++ $^ $(INCLUDES) $(LIBS)  -o $@.exe

multi-cube : multi-cube.cpp ../common/glad.c ../common/shader-c.cpp
	g++ $^ $(INCLUDES) $(LIBS)  -o $@.exe


clean:
	rm -rf *.exe

