#include "GuiInputVectorWidget.hpp"

#include <TinyEngine/Gui/Widgets/GuiButtonWidget.hpp>

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

    void GuiInputVectorWidget::Draw(float deltaTime, IRenderWindowSharedPtr renderWindowPtr)
    {
        GuiWidget::Draw(deltaTime, renderWindowPtr);

        ImGui::Text(_name.c_str());

        EachWidgets([deltaTime, renderWindowPtr](std::string_view id, GuiWidgetSharedPtr widgetPtr)
		{
			widgetPtr->Draw(deltaTime, renderWindowPtr);
		});

        if (_isValueAdd)
        {
            if (_onValueAddCallback)
            {
                _onValueAddCallback();
            }

            _isValueAdd = false;
        }
    }

    void GuiInputVectorWidget::OnValueAdd()
    {
        _isValueAdd = true;
    }
}
