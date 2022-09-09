#include "GuiMetaClassWidget.hpp"

namespace TinyEngine
{
    GuiMetaClassWidgetSharedPtr GuiMetaClassWidget::Create(std::string_view name)
    {
        auto widget = std::make_shared<GuiMetaClassWidget>();
        widget->SetName(name);
        return widget;
    }

    void GuiMetaClassWidget::Draw(float deltaTime,IRenderWindowSharedPtr renderWindowPtr)
    {
        GuiWidget::Draw(deltaTime, renderWindowPtr);

        if (ImGui::TreeNode(_name.c_str()))
        {
            EachWidgets([deltaTime, renderWindowPtr](std::string_view id, GuiWidgetSharedPtr widgetPtr)
		    {
			    widgetPtr->Draw(deltaTime, renderWindowPtr);
		    });

            ImGui::TreePop();
        }
    }
}
