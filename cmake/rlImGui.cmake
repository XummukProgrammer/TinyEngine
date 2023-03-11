set(rlImGui_HEADERS
	deps/rlImGui/rlImGui.h
	deps/rlImGui/rlImGuiColors.h
	deps/rlImGui/extras/IconsFontAwesome6.h
	deps/rlImGui/extras/FA6FreeSolidFontData.h
)

set(rlImGui_SOURCES
	deps/rlImGui/rlImGui.cpp
)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/deps/rlImGui" FILES ${rlImGui_HEADERS} ${rlImGui_SOURCES})
add_library(rlImGui ${rlImGui_HEADERS} ${rlImGui_SOURCES})
target_include_directories(rlImGui PUBLIC deps/rlImGui)
target_link_libraries(rlImGui PUBLIC 
	raylib
	imgui
)
