cmake_minimum_required(VERSION 3.8.2)

project(TinyEngine)

set(CMAKE_CXX_STANDARD 17)

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML COMPONENTS audio graphics main network system window REQUIRED)

set(TGUI_STATIC_LIBRARIES TRUE)
find_package(TGUI REQUIRED)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/deps/pugixml" "${CMAKE_CURRENT_BINARY_DIR}/deps/pugixml")
set_target_properties(pugixml-static PROPERTIES FOLDER "deps")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/deps/fmt" "${CMAKE_CURRENT_BINARY_DIR}/deps/fmt")
set_target_properties(fmt PROPERTIES FOLDER "deps")

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
	pugixml-static
	fmt
)
