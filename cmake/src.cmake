
set(ENGINE_HEADERS
	src/extras/IconsFontAwesome6.h
	src/extras/FA6FreeSolidFontData.h

	src/imgui/imconfig.h
	src/imgui/imgui.h
	src/imgui/imgui_internal.h
	src/imgui/imstb_rectpack.h
	src/imgui/imstb_textedit.h
	src/imgui/imstb_truetype.h
	src/imgui/misc/cpp/imgui_stdlib.h

	src/TinyEngine/TinyEngine.hpp
	
	src/TinyEngine/Libs/rlImGui/rlImGui.h
	src/TinyEngine/Libs/rlImGui/rlImGuiColors.h
)

set(ENGINE_SOURCES
	src/imgui/imgui.cpp
	src/imgui/imgui_demo.cpp
	src/imgui/imgui_draw.cpp
	src/imgui/imgui_tables.cpp
	src/imgui/imgui_widgets.cpp
	src/imgui/misc/cpp/imgui_stdlib.cpp

	src/TinyEngine/TinyEngine.cpp
	
	src/TinyEngine/Libs/rlImGui/rlImGui.cpp
)
