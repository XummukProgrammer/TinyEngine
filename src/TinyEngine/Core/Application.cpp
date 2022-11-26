#include "Application.hpp"

#include <TinyEngine/Core/FileSystem.hpp>
#include <TinyEngine/Core/Logger.hpp>
#include <TinyEngine/Core/States/Common/StartState.hpp>
#include <TinyEngine/Core/States/Common/CloseState.hpp>
#include <TinyEngine/Core/States/Common/StateConditionTransition.hpp>
#include <TinyEngine/Core/Conditions/Common/AndCondition.hpp>
#include <TinyEngine/Core/Conditions/Common/CompareCondition.hpp>
#include <TinyEngine/Core/Conditions/Common/OrCondition.hpp>
#include <TinyEngine/Core/Gui/Gui.hpp>
#include <TinyEngine/Core/Gui/Widgets/GuiWindowWidget.hpp>
#include <TinyEngine/Core/Gui/Widgets/GuiMenuBarWidget.hpp>
#include <TinyEngine/Core/Assets/Assets.hpp>
#include <TinyEngine/Core/Gui/Widgets/GuiFileBrowserWidget.hpp>

namespace TinyEngine
{
	void Application::SetConsoleVars(int argc, char* argv[])
	{
		FileSystem::GetInstance()->SetExecutePath(argv[0]);
	}

	void Application::SetWindowSettings(const RenderWindowSettings& windowSettings)
	{
		auto render = Render::GetInstance();
		render->CreateWindow(windowSettings);
		render->SetOnUpdateCallback(std::bind(&Application::OnUpdate, this));
	}

	void Application::Execute()
	{
		TINY_ENGINE_INFO("Application", "Execute");
		OnInit();
		OnProcess();
		OnDeinit();
	}

	void Application::LoggerSaveToFile()
	{
		Logger::GetInstance()->SaveToFile();
	}

	void Application::Close()
	{
		Render::GetInstance()->Close();
	}

	void Application::OnInit()
	{
		TINY_ENGINE_INFO("Application", "Init");

		{
			auto variable = std::make_shared<ConditionBoolVariable>();
			variable->SetGetter([this]() { return _isClose; });
			_globalContext.AddVariable("IsClose", variable);	
		}

		auto menuBar = Gui::GetInstance()->GetMainWindow()->GetMenuBar();

		GuiMenuBarWidget::Menu projectMenu;
		projectMenu.name = "Project";
		projectMenu.items.push_back({ "Open Project", std::bind(&Application::OnOpenProject, this) });
		projectMenu.items.push_back({ "Save Project", std::bind(&Application::OnSaveProject, this) });
		projectMenu.items.push_back({ "Close", std::bind(&Application::OnClose, this) });
		menuBar->AddMenu(projectMenu);

		GuiMenuBarWidget::Menu assetsMenu;
		assetsMenu.name = "Assets";
		assetsMenu.items.push_back({ "Create Asset File", std::bind(&Application::OnCreateAssetFile, this) });
		menuBar->AddMenu(assetsMenu);
		
		auto fileBrowser = Gui::GetInstance()->GetMainWindow()->GetFileBrowser();
		fileBrowser->SetTypes(".xml");

		_fileBrowserOpenFileSubscriber = EventSubscriber::Create(std::bind(&Application::OnOpenProjectFile, this, std::placeholders::_1));
		fileBrowser->GetOnOpenFileSender().AddSubscriber(_fileBrowserOpenFileSubscriber);

		_world.OnInit();

		Factory::GetInstance()->Register<StartState>();
		Factory::GetInstance()->Register<CloseState>();
		Factory::GetInstance()->Register<StateTransition>();
		Factory::GetInstance()->Register<StateConditionTransition>();
		Factory::GetInstance()->Register<ConditionBoolVariable>();
		Factory::GetInstance()->Register<ConditionIntVariable>();
		Factory::GetInstance()->Register<ConditionFloatVariable>();
		Factory::GetInstance()->Register<ConditionStringVariable>();
		Factory::GetInstance()->Register<ConditionContextVariable>();
		Factory::GetInstance()->Register<CompareCondition>();
		Factory::GetInstance()->Register<OrCondition>();
		Factory::GetInstance()->Register<AndCondition>();
	}

	void Application::OnDeinit()
	{
		TINY_ENGINE_INFO("Application", "Deinit");

		_world.OnDeinit();

		Render::GetInstance()->Destroy();

		_project.GetStates().OnDeinit();

		LoggerSaveToFile();
	}

	void Application::OnProcess()
	{
		TINY_ENGINE_INFO("Application", "Start process");

		Render::GetInstance()->Execute();
	}

	void Application::OnUpdate()
	{
		_project.GetStates().OnUpdate();
		_world.OnUpdate();
	}

	void Application::OnOpenProject()
	{
		Gui::GetInstance()->GetMainWindow()->GetFileBrowser()->ShowOpenFile();
	}

	void Application::OnSaveProject()
	{
		ProjectUtils::SaveProject();
	}

	void Application::OnClose()
	{
		_isClose = 1;
	}

	void Application::OnCreateAssetFile()
	{
		AssetsUtils::CreateAssetFile("test.xml");
	}
	
	void Application::OnOpenProjectFile(EventPtr event)
	{
		auto castedEvent = static_cast<GuiFileBrowserOpenFileEvent*>(event);
		const auto& filePath = castedEvent->GetFilePath();
		
		ProjectUtils::LoadProject(filePath);
	}
}
