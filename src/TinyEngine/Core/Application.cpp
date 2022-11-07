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
