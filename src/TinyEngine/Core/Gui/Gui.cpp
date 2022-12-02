#include "Gui.hpp"

#include <TinyEngine/Core/Gui/Widgets/GuiWindowWidget.hpp>
#include <TinyEngine/Core/Render/RenderWindow.hpp>

#include <TinyEngine/Libs/rlImGui/rlImGui.h>

#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"

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
		//auto& io = ImGui::GetIO();
		//io.IniFilename = nullptr;
		//io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	}

	void Gui::SettingsStyle()
	{
	}

	void Gui::PreInit()
	{
	}

	void Gui::EventReceived()
	{
	}

	void Gui::Update(float deltaTime)
	{
	}

	void Gui::Display()
	{
	}

	void Gui::Shutdown()
	{
	}
}
