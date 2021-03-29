INCLUDES = -I/usr/local/include -Ilib/stb_image

LIBS = -L/usr/local/lib -lglfw  -lGLEW -lassimp -framework OpenGL

CXXFLAGS += -std=c++11 -g

2d : 2d.cpp ../common/shader-c.cpp
	g++ $^ $(CXXFLAGS) $(INCLUDES) $(LIBS) -o $@.exe &&\
	./2d.exe

clean:
	rm -rf *.exe

