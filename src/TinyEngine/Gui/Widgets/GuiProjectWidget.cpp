#include "GuiProjectWidget.hpp"

#include <TinyEngine/Gui/Widgets/GuiLabelWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiButtonWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiInputTextWidget.hpp>

#include <TinyEngine/Core/Logger.hpp>

namespace TinyEngine
{
    GuiProjectWidgetSharedPtr GuiProjectWidget::Create()
    {
        auto widget = std::make_shared<GuiProjectWidget>();
        widget->Load();
		return widget;
    }

    void GuiProjectWidget::Load()
    {
        SetName("ProjectWindow");

        //widget->AddWidget("PrintName", GuiLabelWidget::Create("Print Name:"));
        //widget->AddWidget("PrintPath", GuiLabelWidget::Create("Print Path:"));

        AddWidget("CreateButton", GuiButtonWidget::Create("Create Project", std::bind(&GuiProjectWidget::OnCreate, this)));
        AddWidget("LoadButton", GuiButtonWidget::Create("Load Project", std::bind(&GuiProjectWidget::OnLoad, this)));
        AddWidget("Title", GuiInputTextWidget::Create("Title"));
    }

    void GuiProjectWidget::OnCreate()
    {
        TINY_ENGINE_PRINT_INFO("OnCreate");
    }

    void GuiProjectWidget::OnLoad()
    {
        TINY_ENGINE_PRINT_INFO("OnLoad");
    }
}
