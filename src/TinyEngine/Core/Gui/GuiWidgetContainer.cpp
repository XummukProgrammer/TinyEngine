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
		widget->OnInit();
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

	void GuiWidgetContainer::RemoveWidget(std::string_view id)
	{
		for (const auto& [ widgetId, widget ] : _widgets)
		{
			if (widgetId == id)
			{
				widget->SetIsRemove(true);
				return;
			}
		}
	}

	void GuiWidgetContainer::RemoveAllWidgets()
	{
		for (const auto& [ widgetId, widget ] : _widgets)
		{
			widget->SetIsRemove(true);
		}
	}

	void GuiWidgetContainer::EachWidgets(EachWidgetsCallback callback)
	{
		if (!callback)
		{
			return;
		}

		for (auto it = _widgets.begin(); it != _widgets.end();)
		{
			if (it->second->IsRemove())
			{
				it->second->OnDeinit();
				it = _widgets.erase(it);
			}
			else
			{
				if (it->second->IsActive())
				{
					callback(it->first, it->second);
				}

				++it;
			}
		}
	}
}
