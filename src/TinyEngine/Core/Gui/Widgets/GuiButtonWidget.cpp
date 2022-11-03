﻿#include "GuiButtonWidget.hpp"

namespace TinyEngine
{
    GuiButtonWidgetSharedPtr GuiButtonWidget::Create(std::string_view text, const OnClicked& callback)
    {
        auto widget = std::make_shared<GuiButtonWidget>();
        widget->SetText(text);
        widget->SetOnClickedCallback(callback);
        return widget;
    }

    void GuiButtonWidget::Draw(float deltaTime)
    {
        GuiWidget::Draw(deltaTime);

        if (ImGui::Button(_text.c_str()) && _onClickedCallback)
        {
            _onClickedCallback();
        }
    }
}