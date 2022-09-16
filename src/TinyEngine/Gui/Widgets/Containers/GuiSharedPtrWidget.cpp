#include "GuiSharedPtrWidget.hpp"

#include <TinyEngine/Gui/Widgets/GuiInputTextWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiButtonWidget.hpp>

namespace TinyEngine
{
    GuiSharedPtrWidgetSharedPtr GuiSharedPtrWidget::Create(std::string_view name, bool isInited, const OnInit& callback)
    {
        auto widget = std::make_shared<GuiSharedPtrWidget>();
        widget->SetName(name);
        widget->SetIsInited(isInited);
        widget->SetOnInitCallback(callback);
        widget->Load();
        return widget;
    }

    void GuiSharedPtrWidget::Load()
    {
        if (!IsInited())
        {
            _inputTextPtr = GuiInputTextWidget::Create("Type", "", {});

            AddWidget("Uninited_PointerType", _inputTextPtr);
            AddWidget("Uninited_InitPoint", GuiButtonWidget::Create("Init", std::bind(&GuiSharedPtrWidget::OnInitHandler, this)));
        }
    }

    void GuiSharedPtrWidget::Draw(float deltaTime, IRenderWindowSharedPtr renderWindowPtr)
    {
        GuiWidget::Draw(deltaTime, renderWindowPtr);

        if (ImGui::TreeNode(_name.c_str()))
        {
            EachWidgets([deltaTime, renderWindowPtr](std::string_view id, GuiWidgetSharedPtr widgetPtr)
		    {
			    widgetPtr->Draw(deltaTime, renderWindowPtr);
		    });

            ImGui::TreePop();
        }

        if (_isInit)
        {
            _onInitCallback(_inputTextPtr->GetText());
            _isInit = false;
            _isInited = true;
        }
    }

    void GuiSharedPtrWidget::OnInitHandler()
    {
        _isInit = true;
    }
}
