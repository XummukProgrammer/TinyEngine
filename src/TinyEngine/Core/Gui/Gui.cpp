#include "Gui.hpp"

#include <TinyEngine/Core/Gui/Widgets/GuiWindowWidget.hpp>

#include "imgui.h"
#include "imgui_internal.h"

namespace TinyEngine
{
	void Gui::Init()
	{
		PreInit();

		SettingsIO();
		SettingsStyle();

		SetMainWindow(GuiMainWindowWidget::Create());
	}

	void Gui::Draw(float deltaTime)
	{
		_mainWindowPtr->Draw(deltaTime);
	}

	void Gui::SetMainWindow(GuiMainWindowWidgetSharedPtr mainWindowPtr)
	{
		_mainWindowPtr = mainWindowPtr;
	}

	GuiMainWindowWidgetSharedPtr Gui::GetMainWindow() const
	{
		return _mainWindowPtr;
	}

	void Gui::SettingsIO()
	{
		auto& io = ImGui::GetIO();
		io.IniFilename = nullptr;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	}

	void Gui::SettingsStyle()
	{
		ImGui::StyleColorsClassic();

		ImGuiStyle* style = &ImGui::GetStyle();
		ImVec4* colors = style->Colors;

		style->Alpha = 1.0;
		style->WindowRounding = 3;
		style->GrabRounding = 1;
		style->GrabMinSize = 20;
		style->FrameRounding = 3;

		colors[ImGuiCol_Text]                   = ImVec4(0.00, 1.00, 1.00, 1.00);
		colors[ImGuiCol_TextDisabled]           = ImVec4(0.00, 0.40, 0.41, 1.00);
		colors[ImGuiCol_WindowBg]               = ImVec4(0.00, 0.00, 0.00, 1.00);
		colors[ImGuiCol_ChildBg]                = ImVec4(0.00, 0.00, 0.00, 0.00);
		//colors[ImGuiCol_PopupBg]                = ImVec4(0.11f, 0.11f, 0.14f, 0.92f);
		colors[ImGuiCol_Border]                 = ImVec4(0.00, 1.00, 1.00, 0.65);
		colors[ImGuiCol_BorderShadow]           = ImVec4(0.00, 0.00, 0.00, 0.00);
		colors[ImGuiCol_FrameBg]                = ImVec4(0.44, 0.80, 0.80, 0.18);
		colors[ImGuiCol_FrameBgHovered]         = ImVec4(0.44, 0.80, 0.80, 0.27);
		colors[ImGuiCol_FrameBgActive]          = ImVec4(0.44, 0.81, 0.86, 0.66);
		colors[ImGuiCol_TitleBg]                = ImVec4(0.14, 0.18, 0.21, 0.73);
		colors[ImGuiCol_TitleBgActive]          = ImVec4(0.00, 1.00, 1.00, 0.27);
		colors[ImGuiCol_TitleBgCollapsed]       = ImVec4(0.00, 0.00, 0.00, 0.54);
		colors[ImGuiCol_MenuBarBg]              = ImVec4(0.00, 0.00, 0.00, 0.20);
		colors[ImGuiCol_ScrollbarBg]            = ImVec4(0.22, 0.29, 0.30, 0.71);
		colors[ImGuiCol_ScrollbarGrab]          = ImVec4(0.00, 1.00, 1.00, 0.44);
		colors[ImGuiCol_ScrollbarGrabHovered]   = ImVec4(0.00, 1.00, 1.00, 0.74);
		colors[ImGuiCol_ScrollbarGrabActive]    = ImVec4(0.00, 1.00, 1.00, 1.00);
		colors[ImGuiCol_CheckMark]              = ImVec4(0.00, 1.00, 1.00, 0.68);
		colors[ImGuiCol_SliderGrab]             = ImVec4(0.00, 1.00, 1.00, 0.36);
		colors[ImGuiCol_SliderGrabActive]       = ImVec4(0.00, 1.00, 1.00, 0.76);
		colors[ImGuiCol_Button]                 = ImVec4(0.00, 0.65, 0.65, 0.46);
		colors[ImGuiCol_ButtonHovered]          = ImVec4(0.01, 1.00, 1.00, 0.43);
		colors[ImGuiCol_ButtonActive]           = ImVec4(0.00, 1.00, 1.00, 0.62);
		colors[ImGuiCol_Header]                 = ImVec4(0.00, 1.00, 1.00, 0.33);
		colors[ImGuiCol_HeaderHovered]          = ImVec4(0.00, 1.00, 1.00, 0.42);
		colors[ImGuiCol_HeaderActive]           = ImVec4(0.00, 1.00, 1.00, 0.54);
		//colors[ImGuiCol_Separator]              = ImVec4(0.50f, 0.50f, 0.50f, 0.60f);
		//colors[ImGuiCol_SeparatorHovered]       = ImVec4(0.60f, 0.60f, 0.70f, 1.00f);
		//colors[ImGuiCol_SeparatorActive]        = ImVec4(0.70f, 0.70f, 0.90f, 1.00f);
		colors[ImGuiCol_ResizeGrip]             = ImVec4(0.00, 1.00, 1.00, 0.54);
		colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.00, 1.00, 1.00, 0.74);
		colors[ImGuiCol_ResizeGripActive]       = ImVec4(0.00, 1.00, 1.00, 1.00);
		//colors[ImGuiCol_Tab]                    = ImLerp(colors[ImGuiCol_Header],       colors[ImGuiCol_TitleBgActive], 0.80f);
		//colors[ImGuiCol_TabHovered]             = colors[ImGuiCol_HeaderHovered];
		//colors[ImGuiCol_TabActive]              = ImLerp(colors[ImGuiCol_HeaderActive], colors[ImGuiCol_TitleBgActive], 0.60f);
		//colors[ImGuiCol_TabUnfocused]           = ImLerp(colors[ImGuiCol_Tab],          colors[ImGuiCol_TitleBg], 0.80f);
		//colors[ImGuiCol_TabUnfocusedActive]     = ImLerp(colors[ImGuiCol_TabActive],    colors[ImGuiCol_TitleBg], 0.40f);
		//colors[ImGuiCol_DockingPreview]         = colors[ImGuiCol_Header];
		//colors[ImGuiCol_DockingEmptyBg]         = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
		colors[ImGuiCol_PlotLines]              = ImVec4(0.00, 1.00, 1.00, 1.00);
		colors[ImGuiCol_PlotLinesHovered]       = ImVec4(0.00, 1.00, 1.00, 1.00);
		colors[ImGuiCol_PlotHistogram]          = ImVec4(0.00, 1.00, 1.00, 1.00);
		colors[ImGuiCol_PlotHistogramHovered]   = ImVec4(0.00, 1.00, 1.00, 1.00);
		//colors[ImGuiCol_TableHeaderBg]          = ImVec4(0.27f, 0.27f, 0.38f, 1.00f);
		//colors[ImGuiCol_TableBorderStrong]      = ImVec4(0.31f, 0.31f, 0.45f, 1.00f);   // Prefer using Alpha=1.0 here
		//colors[ImGuiCol_TableBorderLight]       = ImVec4(0.26f, 0.26f, 0.28f, 1.00f);   // Prefer using Alpha=1.0 here
		//colors[ImGuiCol_TableRowBg]             = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		//colors[ImGuiCol_TableRowBgAlt]          = ImVec4(1.00f, 1.00f, 1.00f, 0.07f);
		colors[ImGuiCol_TextSelectedBg]         = ImVec4(0.00, 1.00, 1.00, 0.22);
		//colors[ImGuiCol_DragDropTarget]         = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
		//colors[ImGuiCol_NavHighlight]           = colors[ImGuiCol_HeaderHovered];
		//colors[ImGuiCol_NavWindowingHighlight]  = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
		//colors[ImGuiCol_NavWindowingDimBg]      = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
		colors[ImGuiCol_ModalWindowDimBg]       = ImVec4(0.04, 0.10, 0.09, 0.51);
	}
}
