#include "GuiInputVectorWidget.hpp"

#include <TinyEngine/Core/Gui/Widgets/GuiButtonWidget.hpp>

namespace TinyEngine
{
    GuiInputVectorWidgetSharedPtr GuiInputVectorWidget::Create(std::string_view name)
    {
        auto widget = std::make_shared<GuiInputVectorWidget>();
        widget->SetName(name);
        widget->Load();
        return widget;
    }

    void GuiInputVectorWidget::Load()
    {
        AddWidget("ValueAdd", GuiButtonWidget::Create("Value Add", std::bind(&GuiInputVectorWidget::OnValueAdd, this)));
    }

    void GuiInputVectorWidget::OnValueAdd()
    {
        _isValueAdd = true;
    }

    void GuiInputVectorWidget::OnPostDraw()
    {
        if (_isValueAdd)
        {
            if (_onValueAddCallback)
            {
                _onValueAddCallback();
            }

           _isValueAdd = false;
        }
    }
}
