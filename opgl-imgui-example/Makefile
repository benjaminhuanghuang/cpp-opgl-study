IMGUI_DIR = ./imgui

INCLUDE_PATHS = -I/usr/local/include -I$(IMGUI_DIR)

LIBRARY_PATHS = -L/usr/local/lib

LINKER_FLAGS = -lglfw  -lGLEW -framework OpenGL

FILES = *.cpp imgui/*.cpp

#CXXFLAGS += -DIMGUI_IMPL_OPENGL_LOADER_GL3W

imgui : $(FILES) Makefile
	g++ $(CXXFLAGS) $(FILES) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $@.exe


clean:
	rm -rf *.exe

.PHONY: imgui

