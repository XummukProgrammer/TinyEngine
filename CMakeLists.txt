cmake_minimum_required(VERSION 3.8.2)

project(TinyEngine)

set(CMAKE_CXX_STANDARD 17)

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML COMPONENTS audio graphics main network system window REQUIRED)

find_package(Boost COMPONENTS system filesystem REQUIRED)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/deps/pugixml" "${CMAKE_CURRENT_BINARY_DIR}/deps/pugixml")
set_target_properties(pugixml-static PROPERTIES FOLDER "deps")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/deps/fmt" "${CMAKE_CURRENT_BINARY_DIR}/deps/fmt")
set_target_properties(fmt PROPERTIES FOLDER "deps")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/deps/Candle" "${CMAKE_CURRENT_BINARY_DIR}/deps/Candle")
set_target_properties(Candle-s PROPERTIES FOLDER "deps")
target_compile_definitions(Candle-s PUBLIC -DRADIAL_LIGHT_FIX)

set(IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/deps/imgui")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/deps/imgui-sfml" "${CMAKE_CURRENT_BINARY_DIR}/deps/imgui-sfml")
set_target_properties(ImGui-SFML PROPERTIES FOLDER "deps")

include(cmake/src.cmake)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src" FILES ${ENGINE_HEADERS} ${ENGINE_SOURCES})
add_library(TinyEngine ${ENGINE_HEADERS} ${ENGINE_SOURCES})
target_include_directories(TinyEngine PUBLIC src ${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})
target_link_libraries(TinyEngine PUBLIC 
	sfml-audio
	sfml-graphics
	sfml-main
	sfml-network
	sfml-system
	sfml-window
	pugixml-static
	fmt
	Candle-s
	ImGui-SFML
	${Boost_LIBRARIES}
)
