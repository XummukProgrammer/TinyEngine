#include "GuiTreeContainerWidget.hpp"

namespace TinyEngine
{
    GuiTreeContainerWidgetSharedPtr GuiTreeContainerWidget::Create(std::string_view name)
    {
        auto widget = std::make_shared<GuiTreeContainerWidget>();
        widget->SetName(name);
        return widget;
    }

    void GuiTreeContainerWidget::Draw(float deltaTime)
	{
		GuiWidget::Draw(deltaTime);

        if (ImGui::TreeNode(_name.c_str()))
        {
            GuiWidgetContainer::Draw(deltaTime);

            ImGui::TreePop();
        }

        OnPostDraw();
	}
}
