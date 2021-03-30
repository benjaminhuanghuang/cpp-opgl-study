INCLUDES = -I/usr/local/include -Ilib/imgui

LIBS = -L/usr/local/lib -lglfw  -lGLEW -lassimp -framework OpenGL

FILES = *.cpp ../../common/*.cpp

CXXFLAGS += -std=c++11 -g

light-basic : $(FILES)
	g++ $^ $(CXXFLAGS) $(INCLUDES) $(LIBS) -o $@.exe &&\
	./light-basic.exe

clean:
	rm -rf *.exe
