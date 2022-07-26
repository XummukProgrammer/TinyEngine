#include "GuiWindowWidget.hpp"

namespace TinyEngine
{
	GuiWindowWidget::Ptr GuiWindowWidget::Create(std::string_view name)
	{
		auto widget = std::make_shared<GuiWindowWidget>();
		widget->SetName(name);
		return widget;
	}

	void GuiWindowWidget::Draw(float deltaTime, IRenderWindowPtr renderWindowPtr)
	{
		BeginWindow();

		EachWidgets([deltaTime, renderWindowPtr](std::string_view id, GuiWidgetContainer::GuiWidgetPtr widgetPtr)
		{
			widgetPtr->Draw(deltaTime, renderWindowPtr);
		});

		EndWindow();
	}

	void GuiWindowWidget::BeginWindow()
	{
		ImGui::BeginChild(_name.c_str());
	}

	void GuiWindowWidget::EndWindow()
	{
		ImGui::EndChild();
	}

	GuiMainWindowWidget::Ptr GuiMainWindowWidget::Create()
	{
		auto widget = std::make_shared<GuiMainWindowWidget>();
		widget->SetMenuBar(GuiMenuBarWidget::Create());
		return widget;
	}

	void GuiMainWindowWidget::SetMenuBar(GuiMenuBarWidget::Ptr menuBarPtr)
	{
		_menuBarPtr = menuBarPtr;
		AddWidget("menuBar", _menuBarPtr);
	}

	void GuiMainWindowWidget::BeginWindow()
	{
		ImGui::Begin("MainWindow", false, ImGuiWindowFlags_MenuBar);
	}

	void GuiMainWindowWidget::EndWindow()
	{
		ImGui::End();
	}
}
