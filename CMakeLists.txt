cmake_minimum_required(VERSION 3.5)

project(tetris)
set(CMAKE_CXX_STANDARD 14)
include_directories(engine)

include_directories(/usr/include)
include_directories(/usr/include/glew/build/cmake/)
include_directories(/home/adam/glew-2.0.0/build)
include_directories(/home/adam/workspace/openGL/games/engine)
include_directories(/home/adam/workspace/openGL/games/tetris3/src)

find_package(GLEW REQUIRED COMPONENTS -lglew)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})

add_library(atomic src/main.cpp
			   src/engine/src/vertex_array.h		src/engine/src/vertex_array.cpp
			   src/engine/src/vertex_buffer.h		src/engine/src/vertex_buffer.cpp
			   src/engine/src/element_buffer.h		src/engine/src/element_buffer.cpp
			   src/engine/src/shader.h				src/engine/src/shader.cpp
			   src/engine/src/texture.h				src/engine/src/texture.cpp
			   src/engine/src/color.h				src/engine/src/color.cpp
			   src/engine/src/point.h				src/engine/src/point.cpp
			   src/engine/src/rectangle_parent.h	src/engine/src/rectangle_parent.cpp
			   src/engine/src/rectangle.h			src/engine/src/rectangle.cpp
			   src/engine/src/bordered_rectangle.h  src/engine/src/bordered_rectangle.cpp
			   src/engine/src/square.h				src/engine/src/square.cpp
			   src/engine/src/bordered_square.h		src/engine/src/bordered_square.cpp
			   src/engine/src/window.h				src/engine/src/window.cpp
			   src/block.h							src/block.cpp
			   src/shape.h							src/shape.cpp
			   src/l_shape.h						src/l_shape.cpp
			   src/z_shape.h						src/z_shape.cpp
			   src/staging_area.h					src/staging_area.cpp
			   src/game.h							src/game.cpp
			   )

add_executable(tetris		src/main.cpp
			   src/block.h	src/block.cpp)

target_link_libraries(tetris atomic)
target_link_libraries(tetris GLEW::GLEW)

set(GLFW_BUILD_DOCS		OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS	OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(/usr/include/glfw-3.2.1 bin)
add_subdirectory(/usr/include/glew/build/cmake bin2)
target_link_libraries(tetris glfw glew)

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)
install(FILES "main.cpp" DESTINATION src)
