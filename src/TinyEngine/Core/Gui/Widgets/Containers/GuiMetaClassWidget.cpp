#include "GuiMetaClassWidget.hpp"

namespace TinyEngine
{
    GuiMetaClassWidgetSharedPtr GuiMetaClassWidget::Create(std::string_view name)
    {
        auto widget = std::make_shared<GuiMetaClassWidget>();
        widget->SetName(name);
        return widget;
    }

    void GuiMetaClassWidget::Draw(float deltaTime)
    {
        GuiWidget::Draw(deltaTime);

        if (ImGui::TreeNode(_name.c_str()))
        {
            GuiWidgetContainer::Draw(deltaTime);

            ImGui::TreePop();
        }
    }
}
