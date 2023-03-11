set(IMGUI_HEADERS
	deps/imgui/imconfig.h
	deps/imgui/imgui.h
	deps/imgui/imgui_internal.h
	deps/imgui/imstb_rectpack.h
	deps/imgui/imstb_textedit.h
	deps/imgui/imstb_truetype.h
	deps/imgui/misc/cpp/imgui_stdlib.h
)

set(IMGUI_SOURCES
	deps/imgui/imgui.cpp
	deps/imgui/imgui_demo.cpp
	deps/imgui/imgui_draw.cpp
	deps/imgui/imgui_tables.cpp
	deps/imgui/imgui_widgets.cpp
	deps/imgui/misc/cpp/imgui_stdlib.cpp
)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/deps/imgui" FILES ${IMGUI_HEADERS} ${IMGUI_SOURCES})
add_library(imgui ${IMGUI_HEADERS} ${IMGUI_SOURCES})
target_include_directories(imgui PUBLIC deps/imgui)
