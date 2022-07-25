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
		ImGui::BeginChild(_name.c_str());

		_container.EachWidgets([deltaTime, renderWindowPtr](std::string_view id, GuiWidgetContainer::GuiWidgetPtr widgetPtr)
		{
			widgetPtr->Draw(deltaTime, renderWindowPtr);
		});

		ImGui::EndChild();
	}
}
