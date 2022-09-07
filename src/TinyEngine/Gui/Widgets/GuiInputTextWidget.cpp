#include "GuiInputTextWidget.hpp"

#include <TinyEngine/Render/IRenderWindow.hpp>

namespace TinyEngine
{
    GuiInputTextWidgetSharedPtr GuiInputTextWidget::Create(std::string_view title, std::string_view text, const OnInputed& callback)
    {
        auto widget = std::make_shared<GuiInputTextWidget>();
        widget->SetTitle(title);
        widget->SetText(text);
        widget->SetOnInputedCallback(callback);
        return widget;
    }

    void GuiInputTextWidget::SetText(std::string_view text)
    {
        strcpy_s(_buffer, sizeof(_buffer), text.data());
    }

    std::string GuiInputTextWidget::GetText() const
    {
        return std::string{_buffer};
    }

    void GuiInputTextWidget::Draw(float deltaTime, IRenderWindowSharedPtr renderWindowPtr)
    {
        if (ImGui::InputText(_title.c_str(), _buffer, sizeof(_buffer)) && _onInputedCallback)
        {
            _onInputedCallback(_buffer);
        }
    }
}
