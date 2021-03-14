INCLUDE_PATHS = -I/usr/local/include

LIBRARY_PATHS = -L/usr/local/lib

LINKER_FLAGS = -lglfw  -lGLEW -framework OpenGL

COMMON = ../../common/*.cpp

triangle : triangle.cpp
	g++ $< $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $@.exe

triangle-white : triangle-white.cpp
	g++ $< $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $@.exe


triangle-basic : triangle-basic.cpp
	g++ $< $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $@.exe


triangle-color : triangle-color.cpp $(FILE)
	g++ $< $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $@.exe


clean:
	rm -rf *.exe

