cmake_minimum_required(VERSION 3.14)

project(opgl-demo.exe VERSION 1.0.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#======================= INCLUSION OF Qt =======================#
find_package(OpenGL REQUIRED)
if (WIN32)
  include_directories("C:/GLFW/include" "C:/glew/include")
  link_directories("C:/glew/lib/Release/x64" "C:/GLFW/lib-mingw" )
else (WIN32)
  list(APPEND CMAKE_PREFIX_PATH "/usr/local/Cellar/glfw")
  find_package (GLFW3 REQUIRED)
  find_package (GLEW REQUIRED)
endif (WIN32)

if (APPLE)
  include_directories(/usr/local/include)
  link_directories(/usr/local/lib)
endif (APPLE)

message(STATUS "GLFW: ${GLFW3_LIBARAIE}")

#=================== INCLUSION OF Project Files ================#
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

file(GLOB_RECURSE SOURCES
  "${SOURCE_DIR}/*.h"
  "${SOURCE_DIR}/*.cpp"
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

#===================== LINKING LIBRARIES =======================#
target_link_libraries(${CMAKE_PROJECT_NAME}    
                      ${OPENGL_LIBRARIES}
                      GLFW
                      GLEW)