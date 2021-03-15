INCLUDES = -I/usr/local/include

LIBS = -L/usr/local/lib -lglfw  -lGLEW -framework OpenGL

COMMON = ../common/*.cpp

FLAGS = -Wall

triangle : triangle.cpp
	g++ $< $(INCLUDES) $(LIBS) $(FLAGS) -o $@.exe

triangle-white : triangle-white.cpp
	g++ $< $(INCLUDES) $(LIBS)  -o $@.exe


triangle-basic : triangle-basic.cpp
	g++ $< $(INCLUDES) $(LIBS)  -o $@.exe


triangle-3color : triangle-3color.cpp $(COMMON)
	g++ $^ $(INCLUDES) $(LIBS) $(FLAGS) -o $@.exe


clean:
	rm -rf *.exe

