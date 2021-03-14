INCLUDE_PATHS = -I/usr/local/include

LIBRARY_PATHS = -L/usr/local/lib

LINKER_FLAGS = -lglfw  -lGLEW -framework OpenGL

shader-file : shader-file.cpp
	g++ $< $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $@.exe

shader-demo : shader-demo.cpp
	g++ $< $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $@.exe

clean:
	rm -rf *.exe

