#include "GuiSharedPtrWidget.hpp"

#include <TinyEngine/Gui/Widgets/GuiInputTextWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiButtonWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiStringListBoxWidget.hpp>

namespace TinyEngine
{
    GuiSharedPtrWidgetSharedPtr GuiSharedPtrWidget::Create(std::string_view name, bool isInited, const OnInit& callback, const std::vector<std::string>& inheritorTypes)
    {
        auto widget = std::make_shared<GuiSharedPtrWidget>();
        widget->SetName(name);
        widget->SetIsInited(isInited);
        widget->SetOnInitCallback(callback);
        widget->SetInheritorTypes(inheritorTypes);
        widget->Load();
        return widget;
    }

    void GuiSharedPtrWidget::Load()
    {
        if (!IsInited())
        {
            _typesListWidget = GuiStringListBoxWidget::Create("Type");

            for (const auto& type : _inheritorTypes)
            {
                _typesListWidget->AddItem(type);
            }

            AddWidget("Uninited_PointerType", _typesListWidget);
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
            _onInitCallback(_typesListWidget->GetCurrentItemString());
            _isInit = false;
            _isInited = true;
        }
    }

    void GuiSharedPtrWidget::OnInitHandler()
    {
        _isInit = true;
    }
}
