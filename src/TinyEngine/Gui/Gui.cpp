#include "Gui.hpp"

#include <TinyEngine/Gui/Widgets/GuiWindowWidget.hpp>

#include "imgui.h"
#include "imgui_internal.h"

namespace TinyEngine
{
	void Gui::Init(IRenderWindowSharedPtr renderWindowPtr)
	{
		if (_delegatePtr)
		{
			_delegatePtr->Init(renderWindowPtr);
		}

		SettingsIO();

		SetMainWindow(GuiMainWindowWidget::Create());
	}

	void Gui::EventReceived(IRenderWindowSharedPtr renderWindowPtr)
	{
		if (_delegatePtr)
		{
			_delegatePtr->EventReceived(renderWindowPtr);
		}
	}

	void Gui::Update(float deltaTime, IRenderWindowSharedPtr renderWindowPtr)
	{
		if (_delegatePtr)
		{
			_delegatePtr->Update(deltaTime, renderWindowPtr);
		}
	}

	void Gui::Draw(float deltaTime, IRenderWindowSharedPtr renderWindowPtr)
	{
		_mainWindowPtr->Draw(deltaTime, renderWindowPtr);
	}

	void Gui::Display(IRenderWindowSharedPtr renderWindowPtr)
	{
		if (_delegatePtr)
		{
			_delegatePtr->Display(renderWindowPtr);
		}
	}

	void Gui::Shutdown(IRenderWindowSharedPtr renderWindowPtr)
	{
		if (_delegatePtr)
		{
			_delegatePtr->Shutdown(renderWindowPtr);
		}
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
}
