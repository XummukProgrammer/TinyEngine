#include "GuiInputMapWidget.hpp"

#include <TinyEngine/Gui/Widgets/GuiButtonWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiInputTextWidget.hpp>

namespace TinyEngine
{
    GuiInputMapWidgetSharedPtr GuiInputMapWidget::Create(std::string_view name)
    {
        auto widget = std::make_shared<GuiInputMapWidget>();
        widget->SetName(name);
        widget->Load();
        return widget;
    }

    void GuiInputMapWidget::Load()
    {
        _inputKeyWidget = GuiInputTextWidget::Create("Input key", "", {});

        AddWidget("InputKey", _inputKeyWidget);
        AddWidget("CreateValue", GuiButtonWidget::Create("Create value", std::bind(&GuiInputMapWidget::OnAddValue, this)));
    }

    void GuiInputMapWidget::Draw(float deltaTime, IRenderWindowSharedPtr renderWindowPtr)
    {
        GuiWidget::Draw(deltaTime, renderWindowPtr);

        if (ImGui::TreeNode(_name.c_str()))
        {
            EachWidgets([deltaTime, renderWindowPtr](std::string_view id, GuiWidgetSharedPtr widgetPtr)
		    {
			    widgetPtr->Draw(deltaTime, renderWindowPtr);
		    });

            if (_isValueAdd && _onValueAddCallback)
            {
                _onValueAddCallback(_inputKeyWidget->GetText());
                _inputKeyWidget->SetText("");
                _isValueAdd = false;
            }

            ImGui::TreePop();
        }
    }

    void GuiInputMapWidget::OnAddValue()
    {
        if (_inputKeyWidget->GetText().empty())
        {
            return;
        }

        _isValueAdd = true;
    }
}
