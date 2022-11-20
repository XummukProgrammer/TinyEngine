#include "StartState.hpp"

#include <TinyEngine/Core/Application.hpp>
#include <TinyEngine/Core/Gui/Gui.hpp>
#include <TinyEngine/Core/Gui/Widgets/Containers/GuiPropertiesWidget.hpp>

namespace TinyEngine
{
	void StartState::OnUpdate()
	{
	}

	void StartState::OnEnter()
	{
		// For tests
        auto mainWindowWidgetPtr = TinyEngine::Gui::GetInstance()->GetMainWindow();

        auto propertiesWindow = TinyEngine::GuiPropertiesWidget::Create();
		propertiesWindow->InitFromMetaClass(&TinyEngine::Application::GetInstance()->GetProject());
		mainWindowWidgetPtr->AddWidget(propertiesWindow);
	}

	void StartState::OnExit()
	{
	}
}
