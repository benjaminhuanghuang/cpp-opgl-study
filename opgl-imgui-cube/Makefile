IMGUI_DIR = ../common/imgui 

INCLUDES = -I/usr/local/include -I$(IMGUI_DIR) -I../common

LIBS = -L/usr/local/lib -lglfw  -lGLEW -framework OpenGL

FILES = ../common/imgui/*.cpp ../common/glad.c ../common/shader-c.cpp

CXXFLAGS += -g

3dCube : 3dCube.cpp $(FILES)
	g++ $^ $(CXXFLAGS) $(INCLUDES) $(LIBS) -o $@.exe &&\
	./3dCube.exe


clean:
	rm -rf *.exe

.PHONY: imgui

