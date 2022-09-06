#include "GuiInputMapWidget.hpp"

namespace TinyEngine
{
    GuiInputMapWidgetSharedPtr GuiInputMapWidget::Create()
    {
        auto widget = std::make_shared<GuiInputMapWidget>();
        widget->Load();
        return widget;
    }

    void GuiInputMapWidget::Load()
    {
    }

    void GuiInputMapWidget::Draw(float deltaTime, IRenderWindowSharedPtr renderWindowPtr)
    {
        GuiWidget::Draw(deltaTime, renderWindowPtr);

        EachWidgets([deltaTime, renderWindowPtr](std::string_view id, GuiWidgetSharedPtr widgetPtr)
		{
			widgetPtr->Draw(deltaTime, renderWindowPtr);
		});
    }
}
