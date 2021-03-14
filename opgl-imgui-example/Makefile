IMGUI_DIR = ./imgui

INCLUDES = -I/usr/local/include -I$(IMGUI_DIR)

LIBS = -L/usr/local/lib -lglfw  -lGLEW -framework OpenGL

FILES = imgui/*.cpp glad.c

#CXXFLAGS += -DIMGUI_IMPL_OPENGL_LOADER_GL3W

basic : basic.cpp Makefile
	g++ $< $(CXXFLAGS) $(FILES) $(INCLUDES) $(LIBS) -o $@.exe

imgui : $(FILES) Makefile
	g++ $(CXXFLAGS) $(FILES) $(INCLUDES) $(LIBS) -o $@.exe


clean:
	rm -rf *.exe

.PHONY: imgui

