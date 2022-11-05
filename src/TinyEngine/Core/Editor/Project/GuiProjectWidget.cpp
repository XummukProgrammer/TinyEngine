#include "GuiProjectWidget.hpp"

#include <TinyEngine/Core/Gui/Widgets/GuiButtonWidget.hpp>
#include <TinyEngine/Core/Gui/Widgets/GuiInputTextWidget.hpp>

#include <TinyEngine/Core/Application.hpp>
#include <TinyEngine/Core/Project.hpp>

#include <TinyEngine/Core/Gui/Widgets/Containers/GuiPropertiesWidget.hpp>
#include <TinyEngine/Core/Gui/Widgets/GuiWindowWidget.hpp>
#include <TinyEngine/Core/Gui/Gui.hpp>

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

        _loadProjectFileWidget = GuiInputTextWidget::Create("File", "project.xml", {});

        AddWidget("Title", _loadProjectFileWidget);
        AddWidget("LoadButton", GuiButtonWidget::Create("Load Project", std::bind(&GuiProjectWidget::OnLoad, this)));
    }

    void GuiProjectWidget::OnLoad()
    {
        ProjectUtils::LoadProject(&Application::GetInstance()->GetProject(), 
            _loadProjectFileWidget->GetText(), 
            &Application::GetInstance()->GetWorld());
        SetIsActive(false);

        // For tests
        auto mainWindowWidgetPtr = TinyEngine::Gui::GetInstance()->GetMainWindow();

        auto propertiesWindow = TinyEngine::GuiPropertiesWidget::Create();
		propertiesWindow->InitFromMetaClass(&TinyEngine::Application::GetInstance()->GetProject());
		mainWindowWidgetPtr->AddWidget(propertiesWindow);
    }
}
