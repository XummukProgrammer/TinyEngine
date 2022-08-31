#include "GuiInputTextWidget.hpp"

#include <TinyEngine/Render/IRenderWindow.hpp>

namespace TinyEngine
{
    GuiInputTextWidgetSharedPtr GuiInputTextWidget::Create(std::string_view title, const OnInputed& callback)
    {
        auto widget = std::make_shared<GuiInputTextWidget>();
        widget->SetTitle(title);
        widget->SetOnInputedCallback(callback);
        return widget;
    }

    void GuiInputTextWidget::Draw(float deltaTime, IRenderWindowSharedPtr renderWindowPtr)
    {
        if (ImGui::InputText(_title.c_str(), _buffer, sizeof(_buffer)) && _onInputedCallback)
        {
            _onInputedCallback(_buffer);
        }
    }
}
