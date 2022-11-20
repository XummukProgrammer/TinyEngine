#include "Application.hpp"

#include <TinyEngine/Core/Debug.hpp>
#include <TinyEngine/Core/FileSystem.hpp>
#include <TinyEngine/Core/Logger.hpp>
#include <TinyEngine/Core/Assets/Assets.hpp>
#include <TinyEngine/Core/Assets/Asset.hpp>
#include <TinyEngine/Core/Assets/AssetHolder.hpp>
#include <TinyEngine/Core/Assets/AssetLoader.hpp>
#include <TinyEngine/Core/Assets/AssetTexture.hpp>
#include <TinyEngine/Core/Render/Render.hpp>
#include <TinyEngine/Core/Gui/Gui.hpp>
#include <TinyEngine/Core/Data/Factory.hpp>
#include <TinyEngine/Core/Project.hpp>
#include <TinyEngine/Core/Editor/Project/GuiProjectWidget.hpp>
#include <TinyEngine/Core/States/State.hpp>
#include <TinyEngine/Core/States/Common/StateConditionTransition.hpp>
#include <TinyEngine/Core/Conditions/ConditionVariable.hpp>
#include <TinyEngine/Core/Conditions/ConditionContextVariable.hpp>
#include <TinyEngine/Core/Conditions/Common/AndCondition.hpp>
#include <TinyEngine/Core/Conditions/Common/CompareCondition.hpp>
#include <TinyEngine/Core/Conditions/Common/OrCondition.hpp>

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

		_world.OnInit();

		Factory::GetInstance()->Register<State>();
		Factory::GetInstance()->Register<StateTransition>();
		Factory::GetInstance()->Register<StateConditionTransition>();
		Factory::GetInstance()->Register<ConditionIntVariable>();
		Factory::GetInstance()->Register<ConditionFloatVariable>();
		Factory::GetInstance()->Register<ConditionStringVariable>();
		Factory::GetInstance()->Register<ConditionContextVariable>();
		Factory::GetInstance()->Register<CompareCondition>();
		Factory::GetInstance()->Register<OrCondition>();
		Factory::GetInstance()->Register<AndCondition>();

		auto mainWindowWidgetPtr = TinyEngine::Gui::GetInstance()->GetMainWindow();

        auto projectWidget = TinyEngine::GuiProjectWidget::Create();
		mainWindowWidgetPtr->AddWidget(projectWidget);
	}

	void Application::OnDeinit()
	{
		TINY_ENGINE_INFO("Application", "Deinit");

		_world.OnDeinit();

		Render::GetInstance()->Destroy();

		LoggerSaveToFile();

		ProjectUtils::SaveProject(&GetProject());
	}

	void Application::OnProcess()
	{
		TINY_ENGINE_INFO("Application", "Start process");

		Render::GetInstance()->Execute();
	}

	void Application::OnUpdate()
	{
		_world.OnUpdate();
	}
}
