IMGUI_DIR = ../common/imgui

INCLUDES = -I/usr/local/include -I$(IMGUI_DIR)

LIBS = -L/usr/local/lib -lglfw  -lGLEW -framework OpenGL

FILES = ../common/imgui/*.cpp ../common/glad.c ../common/shader-c.cpp

#CXXFLAGS += -DIMGUI_IMPL_OPENGL_LOADER_GL3W

3dCube : 3dCube.cpp $(FILES)
	g++ $^ $(CXXFLAGS) $(INCLUDES) $(LIBS) -o $@.exe &&\
	./3dCube.exe


clean:
	rm -rf *.exe

.PHONY: imgui

