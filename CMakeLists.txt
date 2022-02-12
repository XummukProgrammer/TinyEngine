cmake_minimum_required(VERSION 3.8.2)

project(TinyEngine)

set(CMAKE_CXX_STANDARD 17)

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML COMPONENTS audio graphics main network system window REQUIRED)

set(TGUI_STATIC_LIBRARIES TRUE)
find_package(TGUI REQUIRED)

include(cmake/src.cmake)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src" FILES ${ENGINE_HEADERS} ${ENGINE_SOURCES})
add_library(TinyEngine ${ENGINE_HEADERS} ${ENGINE_SOURCES})
target_include_directories(TinyEngine PUBLIC src)
target_link_libraries(TinyEngine PUBLIC 
	sfml-audio
	sfml-graphics
	sfml-main
	sfml-network
	sfml-system
	sfml-window
	tgui
)
