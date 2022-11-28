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
#include <TinyEngine/Core/Assets/Common/AssetHolder.hpp>
#include <TinyEngine/Core/Assets/Common/LinkAsset.hpp>
#include <TinyEngine/Core/Assets/Common/TextureAsset.hpp>
#include <TinyEngine/Core/Gui/Widgets/GuiFileBrowserWidget.hpp>
#include <TinyEngine/Core/Gui/Widgets/Containers/GuiPropertiesWidget.hpp>

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

		OnRegisterFactory();
		OnLoadGlobalContext();
		OnLoadGui();

		_world.OnInit();
	}

	void Application::OnDeinit()
	{
		TINY_ENGINE_INFO("Application", "Deinit");

		_world.OnDeinit();

		Render::GetInstance()->Destroy();

		if (auto states = _project.GetStates())
		{
			states->OnDeinit();
		}

		LoggerSaveToFile();
	}

	void Application::OnProcess()
	{
		TINY_ENGINE_INFO("Application", "Start process");

		Render::GetInstance()->Execute();
	}

	void Application::OnUpdate()
	{
		if (_isOpenProjectFile)
		{
			ProjectUtils::LoadProject(_projectFilePath);
			_isOpenProjectFile = false;
		}

		if (auto states = _project.GetStates())
		{
			states->OnUpdate();
		}
		
		_world.OnUpdate();
	}

	void Application::OnRegisterFactory()
	{
		Factory::GetInstance()->Register<AssetHolder>();
		Factory::GetInstance()->Register<LinkAsset>();
		Factory::GetInstance()->Register<TextureAsset>();

		Factory::GetInstance()->Register<States>();
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

	void Application::OnLoadGlobalContext()
	{
		{
			auto variable = std::make_shared<ConditionBoolVariable>();
			variable->SetGetter([this]() { return _isClose; });
			_globalContext.AddVariable("IsClose", variable);	
		}
	}

	void Application::OnLoadGui()
	{
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
		
		GuiMenuBarWidget::Menu propertiesMenu;
		propertiesMenu.name = "Properties";
		propertiesMenu.items.push_back({ "Open Project Properties", std::bind(&Application::OnOpenProjectProperties, this) });
		propertiesMenu.items.push_back({ "Open Asset File Properties", std::bind(&Application::OnOpenAssetFileProperties, this) });
		menuBar->AddMenu(propertiesMenu);

		auto fileBrowser = Gui::GetInstance()->GetMainWindow()->GetFileBrowser();
		fileBrowser->SetTypes(".xml");

		_fileBrowserOpenFileSubscriber = EventSubscriber::Create(std::bind(&Application::OnOpenFileBrowserHandler, this, std::placeholders::_1));
		fileBrowser->GetOnOpenFileSender().AddSubscriber(_fileBrowserOpenFileSubscriber);

		_fileBrowserSaveFileSubscriber = EventSubscriber::Create(std::bind(&Application::OnSaveFileBrowserHandler, this, std::placeholders::_1));
		fileBrowser->GetOnSaveFileSender().AddSubscriber(_fileBrowserSaveFileSubscriber);
	}

	void Application::OnOpenProject()
	{
		auto fileBrowser = Gui::GetInstance()->GetMainWindow()->GetFileBrowser();
		fileBrowser->SetSource(OPEN_PROJECT_SOURCE);
		fileBrowser->ShowOpenFile();
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
		auto fileBrowser = Gui::GetInstance()->GetMainWindow()->GetFileBrowser();
		fileBrowser->SetSource(CREATE_ASSET_SOURCE);
		fileBrowser->ShowSaveFile();
	}

	void Application::OnOpenProjectProperties()
	{
		auto mainWindowWidgetPtr = TinyEngine::Gui::GetInstance()->GetMainWindow();
		auto propertiesWindow = mainWindowWidgetPtr->GetWidget<GuiPropertiesWidget>("Properties");
		propertiesWindow->InitFromMetaClass(&TinyEngine::Application::GetInstance()->GetProject());
	}

	void Application::OnOpenAssetFileProperties()
	{
		auto mainWindowWidgetPtr = TinyEngine::Gui::GetInstance()->GetMainWindow();
		auto propertiesWindow = mainWindowWidgetPtr->GetWidget<GuiPropertiesWidget>("Properties");
		auto asset = Assets::GetInstance()->GetAsset<States>("States");
		propertiesWindow->InitFromMetaClass(asset.get());
	}
	
	void Application::OnOpenFileBrowserHandler(EventPtr event)
	{
		auto castedEvent = static_cast<GuiFileBrowserOpenFileEvent*>(event);
		const auto& source = castedEvent->GetSource();
		const auto& filePath = castedEvent->GetFilePath();

		if (source == OPEN_PROJECT_SOURCE)
		{
			_projectFilePath = castedEvent->GetFilePath();
			_isOpenProjectFile = true;
		}
	}

	void Application::OnSaveFileBrowserHandler(EventPtr event)
	{
		auto castedEvent = static_cast<GuiFileBrowserSaveFileEvent*>(event);
		const auto& source = castedEvent->GetSource();
		const auto& filePath = castedEvent->GetFilePath();

		if (source == CREATE_ASSET_SOURCE)
		{
			AssetsUtils::CreateAssetFile(filePath, "States");
		}
	}
}
