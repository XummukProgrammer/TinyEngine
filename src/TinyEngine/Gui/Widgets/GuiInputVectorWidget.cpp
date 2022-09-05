#include "GuiInputVectorWidget.hpp"

namespace TinyEngine
{
    GuiInputVectorWidgetSharedPtr GuiInputVectorWidget::Create(std::string_view name)
    {
        auto widget = std::make_shared<GuiInputVectorWidget>();
        widget->SetName(name);
        return widget;
    }

    void GuiInputVectorWidget::Draw(float deltaTime, IRenderWindowSharedPtr renderWindowPtr)
    {
        GuiWidget::Draw(deltaTime, renderWindowPtr);

        ImGui::Text(_name.c_str());

        EachWidgets([deltaTime, renderWindowPtr](std::string_view id, GuiWidgetSharedPtr widgetPtr)
		{
			widgetPtr->Draw(deltaTime, renderWindowPtr);
		});
    }
}
