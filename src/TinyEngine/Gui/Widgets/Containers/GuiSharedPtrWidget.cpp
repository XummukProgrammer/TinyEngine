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
        _typesListWidget = GuiStringListBoxWidget::Create("Type");
        _buttonWidget = GuiButtonWidget::Create("Init", std::bind(&GuiSharedPtrWidget::OnInitHandler, this));

        for (const auto& type : _inheritorTypes)
        {
            _typesListWidget->AddItem(type);
        }

        AddWidget("Uninited_PointerType", _typesListWidget);
        AddWidget("Uninited_InitPoint", _buttonWidget);

        _typesListWidget->SetIsActive(!IsInited());
        _buttonWidget->SetIsActive(!IsInited());
    }

    void GuiSharedPtrWidget::Draw(float deltaTime)
    {
        GuiWidget::Draw(deltaTime);

        if (ImGui::TreeNode(_name.c_str()))
        {
            GuiWidgetContainer::Draw(deltaTime);

            ImGui::TreePop();
        }

        if (_isInit)
        {
            _onInitCallback(_typesListWidget->GetCurrentItemString());
            _isInit = false;
            _isInited = true;

            _typesListWidget->SetIsActive(false);
            _buttonWidget->SetIsActive(false);
        }
    }

    void GuiSharedPtrWidget::OnInitHandler()
    {
        _isInit = true;
    }
}
