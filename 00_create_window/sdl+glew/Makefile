# 源文件
SRC = demo.cpp

# 头文件文件夹
INC_DIR += -ID:\msys2\opt\SDL2\include 
INC_DIR += -ID:\msys2\opt\glfw\include
INC_DIR += -ID:\msys2\opt\glew\include

# 库文件文件夹
LIB_DIR += -LD:\msys2\opt\SDL2\lib
LIB_DIR += -LD:\msys2\opt\glfw\lib
LIB_DIR += -LD:\msys2\opt\glew\lib

# 链接库
LIB = -lmingw32 -lSDL2main -lSDL2 -lglew32 -lglfw3 -lopengl32

# 编译参数
CFLAGS = $(INC_DIR) $(LIB_DIR) $(LIB) -O2 -mwindows

a.exe: $(SRC)
    g++ $(SRC) $(CFLAGS) -o sdl-demo.exe