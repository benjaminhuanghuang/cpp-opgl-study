IMGUI_DIR = ./imgui

INCLUDES = -I/usr/local/include -I$(IMGUI_DIR)

LIBS = -L/usr/local/lib -lglfw  -lGLEW -framework OpenGL

FILES = imgui/*.cpp glad.c ../common/shader-c.cpp

#CXXFLAGS += -DIMGUI_IMPL_OPENGL_LOADER_GL3W

basic : basic.cpp
	g++ $< $(CXXFLAGS) $(FILES) $(INCLUDES) $(LIBS) -o $@.exe &&\
	./basic.exe

red-triangle : red-triangle.cpp 
	g++ $^ $(CXXFLAGS) $(FILES) $(INCLUDES) $(LIBS) -o $@.exe &&\
	./red-triangle.exe

color-triangle : color-triangle.cpp 
	g++ $^ $(CXXFLAGS) $(FILES) $(INCLUDES) $(LIBS) -o $@.exe &&\
	./color-triangle.exe

cube : cube.cpp
	g++ $^ $(CXXFLAGS) $(FILES) $(INCLUDES) $(LIBS) -o $@.exe

cube-turn : cube-turn.cpp
	g++ $^ $(CXXFLAGS) $(FILES) $(INCLUDES) $(LIBS) -o $@.exe

imgui : $(FILES)
	g++ $(CXXFLAGS) $(FILES) $(INCLUDES) $(LIBS) -o $@.exe


clean:
	rm -rf *.exe

.PHONY: imgui

