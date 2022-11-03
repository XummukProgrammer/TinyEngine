#include "GuiCheckboxWidget.hpp"

namespace TinyEngine
{
    GuiCheckboxWidgetSharedPtr GuiCheckboxWidget::Create(std::string_view title, bool value, const OnChanged& callback)
    {
        auto widget = std::make_shared<GuiCheckboxWidget>();
        widget->SetTitle(title);
        widget->SetValue(value);
        widget->SetOnChangedCallback(callback);
        return widget;
    }

    void GuiCheckboxWidget::Draw(float deltaTime)
    {
        GuiWidget::Draw(deltaTime);

        if (ImGui::Checkbox(_title.c_str(), &_value) && _onChangedCallback)
        {
            _onChangedCallback(_value);
        }
    }
}
