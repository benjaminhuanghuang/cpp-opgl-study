APP_NAME = main.exe

SRCS = *.cpp
APP_PATH = $(APP_NAME)

SRC= $(wildcard $(SRCS))

# CC specifies which compiler we're using
CC = g++
RM = rm

# INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -I/usr/local/include -I/usr/local/Cellar/sdl2/2.0.9_1/include/SDL2

# LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -L/usr/local/lib

# COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

ifeq ($(DEBUG),yes)
	COMPILER_FLAGS += -g
endif

# LINKER_FLAGS specifies the libraries we're linking against
# Cocoa, IOKit, and CoreVideo are needed for static GLFW3.
LINKER_FLAGS = -lsdl2 -lglfw -lGLEW -framework OpenGL#-framework Cocoa 


# APP_NAME specifies the name of our exectuable
#This is the target that compiles our executable
$(APP_NAME) : $(SRCS)
	$(CC) $< $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(APP_PATH)
	
# clean all sources
clean:
	$(RM) -rf $(OBJS)
	$(RM) -rf $(SRC_PATH)/*o
	$(RM) -rf $(APP_PATH)

