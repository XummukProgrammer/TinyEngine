#include "GuiInputTextWidget.hpp"

#include <TinyEngine/Render/IRenderWindow.hpp>

namespace TinyEngine
{
    GuiInputTextWidgetSharedPtr GuiInputTextWidget::Create(std::string_view title)
    {
        auto widget = std::make_shared<GuiInputTextWidget>();
        widget->SetTitle(title);
        return widget;
    }

    void GuiInputTextWidget::Draw(float deltaTime, IRenderWindowSharedPtr renderWindowPtr)
    {
        if (ImGui::InputText(_title.c_str(), _buffer, sizeof(_buffer)))
        {
        }
    }
}
