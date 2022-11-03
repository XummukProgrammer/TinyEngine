#include "GuiWidgetContainer.hpp"

#include <TinyEngine/Core/Gui/GuiWidget.hpp>

namespace TinyEngine
{
	void GuiWidgetContainer::Draw(float deltaTime)
	{
		EachWidgets([deltaTime](std::string_view id, GuiWidgetSharedPtr widgetPtr)
		{
			widgetPtr->Draw(deltaTime);
		});
	}

	void GuiWidgetContainer::AddWidget(std::string_view id, GuiWidgetSharedPtr widget)
	{
		_widgets.push_back({ std::string{id}, widget });
	}

	void GuiWidgetContainer::AddWidget(GuiWidgetSharedPtr widget)
	{
		std::string id = "widget_" + std::to_string(_widgets.size());
		AddWidget(id, widget);
	}

	bool GuiWidgetContainer::HasWidget(std::string_view id) const
	{
		for (const auto& [ widgetId, widget ] : _widgets)
		{
			if (widgetId == id)
			{
				return true;
			}
		}
		return false;
	}

	void GuiWidgetContainer::EachWidgets(EachWidgetsCallback callback)
	{
		if (!callback)
		{
			return;
		}

		for (const auto& [ id, widget ] : _widgets)
		{
			if (widget->IsActive())
			{
				callback(id, widget);
			}
		}
	}
}
