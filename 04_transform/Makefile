INCLUDES = -I/usr/local/include

LIBS = -L/usr/local/lib -lglfw  -lGLEW -framework OpenGL

FILES = ../common/shader-c.cpp

#CXXFLAGS += -DIMGUI_IMPL_OPENGL_LOADER_GL3W

uniform-tranf : uniform-transform.cpp
	g++ $< $(CXXFLAGS) $(FILES) $(INCLUDES) $(LIBS) -o $@.exe &&\
	./uniform-tranf.exe

clean:
	rm -rf *.exe

.PHONY: imgui

