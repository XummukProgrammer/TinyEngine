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

namespace TinyEngine
{
	Application& Application::Init(int argc, char* argv[], const RenderWindowSettings& windowSettings, ApplicationDelegateUniquePtr&& delegate)
	{
		FileSystem::GetInstance()->SetExecutePath(argv[0]);
		_delegate = std::move(delegate);

		auto render = Render::GetInstance();
		render->CreateWindow(windowSettings);
		render->SetOnUpdateCallback(std::bind(&Application::OnUpdate, this));

		return *this;
	}

	void Application::Execute()
	{
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
		if (_delegate)
		{
			_delegate->OnInit();
		}

		_world.OnInit();
	}

	void Application::OnDeinit()
	{
		if (_delegate)
		{
			_delegate->OnDeinit();
		}

		_world.OnDeinit();

		Render::GetInstance()->Destroy();

		LoggerSaveToFile();
	}

	void Application::OnProcess()
	{
		Render::GetInstance()->Execute();
	}

	void Application::OnUpdate()
	{
		_world.OnUpdate();
	}
}
