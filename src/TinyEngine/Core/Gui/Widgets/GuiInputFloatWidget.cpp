#include "GuiInputFloatWidget.hpp"

namespace TinyEngine
{
    GuiInputFloatWidgetSharedPtr GuiInputFloatWidget::Create(std::string_view title, float value, const OnInputed& callback)
    {
        auto widget = std::make_shared<GuiInputFloatWidget>();
        widget->SetTitle(title);
        widget->SetValue(value);
        widget->SetOnInputedCallback(callback);
        return widget;
    }

    void GuiInputFloatWidget::Draw(float deltaTime)
    {
        GuiWidget::Draw(deltaTime);

        if (ImGui::InputFloat(_title.c_str(), &_value) && _onInputedCallback)
        {
            _onInputedCallback(_value);
        }
    }
}
