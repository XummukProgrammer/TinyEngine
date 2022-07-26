#include "Gui.hpp"

#include <TinyEngine/Gui/Widgets/GuiWindowWidget.hpp>

#include "imgui.h"
#include "imgui_internal.h"

namespace TinyEngine
{
	void Gui::Init(IRenderWindowPtr renderWindowPtr)
	{
		if (_delegatePtr)
		{
			_delegatePtr->Init(renderWindowPtr);
		}

		SettingsIO();

		SetMainWindow(GuiMainWindowWidget::Create());
	}

	void Gui::EventReceived(IRenderWindowPtr renderWindowPtr)
	{
		if (_delegatePtr)
		{
			_delegatePtr->EventReceived(renderWindowPtr);
		}
	}

	void Gui::Update(float deltaTime, IRenderWindowPtr renderWindowPtr)
	{
		if (_delegatePtr)
		{
			_delegatePtr->Update(deltaTime, renderWindowPtr);
		}
	}

	void Gui::Draw(float deltaTime, IRenderWindowPtr renderWindowPtr)
	{
		_mainWindowPtr->Draw(deltaTime, renderWindowPtr);
	}

	void Gui::Display(IRenderWindowPtr renderWindowPtr)
	{
		if (_delegatePtr)
		{
			_delegatePtr->Display(renderWindowPtr);
		}
	}

	void Gui::Shutdown(IRenderWindowPtr renderWindowPtr)
	{
		if (_delegatePtr)
		{
			_delegatePtr->Shutdown(renderWindowPtr);
		}
	}

	void Gui::SetMainWindow(GuiMainWindowWidgetPtr mainWindowPtr)
	{
		_mainWindowPtr = mainWindowPtr;
	}

	GuiMainWindowWidgetPtr Gui::GetMainWindow() const
	{
		return _mainWindowPtr;
	}

	void Gui::SettingsIO()
	{
		auto& io = ImGui::GetIO();
		io.IniFilename = nullptr;
	}
}
