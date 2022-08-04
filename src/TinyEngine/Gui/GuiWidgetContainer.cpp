#include "GuiWidgetContainer.hpp"

#include <TinyEngine/Gui/GuiWidget.hpp>

namespace TinyEngine
{
	void GuiWidgetContainer::Draw(float deltaTime, IRenderWindowSharedPtr renderWindowPtr)
	{
		for (const auto& [ id, widget ] : _widgets)
		{
			widget->Draw(deltaTime, renderWindowPtr);
		}
	}

	void GuiWidgetContainer::AddWidget(std::string_view id, GuiWidgetSharedPtr widget)
	{
		_widgets[std::string{id}] = widget;
	}

	bool GuiWidgetContainer::HasWidget(std::string_view id) const
	{
		return _widgets.find(std::string{id}) != _widgets.end();
	}

	void GuiWidgetContainer::EachWidgets(EachWidgetsCallback callback)
	{
		if (!callback)
		{
			return;
		}

		for (const auto& [ id, widget ] : _widgets)
		{
			callback(id, widget);
		}
	}
}
