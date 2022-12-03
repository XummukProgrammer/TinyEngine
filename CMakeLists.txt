cmake_minimum_required(VERSION 3.7)

project(TinyEngine)

if(POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif()

if(POLICY CMP0077)
  cmake_policy(SET CMP0077 NEW)
endif()

set(CMAKE_CXX_STANDARD 17)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/deps/pugixml" "${CMAKE_CURRENT_BINARY_DIR}/deps/pugixml")
set_target_properties(pugixml-static PROPERTIES FOLDER "deps")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/deps/fmt" "${CMAKE_CURRENT_BINARY_DIR}/deps/fmt")
set_target_properties(fmt PROPERTIES FOLDER "deps")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/deps/magic_enum" "${CMAKE_CURRENT_BINARY_DIR}/deps/magic_enum")
set_target_properties(magic_enum PROPERTIES FOLDER "deps")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/deps/stacktrace" "${CMAKE_CURRENT_BINARY_DIR}/deps/stacktrace")
set_target_properties(stacktrace PROPERTIES FOLDER "deps")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/deps/raylib" "${CMAKE_CURRENT_BINARY_DIR}/deps/raylib")
set_target_properties(raylib PROPERTIES FOLDER "deps")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/deps/raylib-cpp" "${CMAKE_CURRENT_BINARY_DIR}/deps/raylib-cpp")
set_target_properties(raylib_cpp PROPERTIES FOLDER "deps")

include(cmake/src.cmake)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src" FILES ${ENGINE_HEADERS} ${ENGINE_SOURCES})
add_library(TinyEngine ${ENGINE_HEADERS} ${ENGINE_SOURCES})
target_include_directories(TinyEngine PUBLIC src)
target_link_libraries(TinyEngine PUBLIC 
	pugixml-static
	fmt
	magic_enum
	stacktrace
	raylib
	raylib_cpp
)

# Checks if OSX and links appropriate frameworks (only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
