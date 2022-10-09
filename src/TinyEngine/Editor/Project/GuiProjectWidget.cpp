#include "GuiProjectWidget.hpp"

#include <TinyEngine/Gui/Widgets/GuiButtonWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiInputTextWidget.hpp>

#include <TinyEngine/Core/Application.hpp>
#include <TinyEngine/Editor/Project/Project.hpp>

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

        _loadProjectFileWidget = GuiInputTextWidget::Create("File", "File", {});

        AddWidget("Title", _loadProjectFileWidget);
        AddWidget("LoadButton", GuiButtonWidget::Create("Load Project", std::bind(&GuiProjectWidget::OnLoad, this)));
    }

    void GuiProjectWidget::OnLoad()
    {
        ProjectUtils::LoadProject(&Application::GetInstance()->GetProject(), _loadProjectFileWidget->GetText());
        SetIsActive(false);
    }
}
