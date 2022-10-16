﻿#ifndef _APPLICATION_HEADER_
#define _APPLICATION_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Data/Singleton.hpp>
#include <TinyEngine/Render/RenderWindowSettings.hpp>
#include <TinyEngine/Editor/Project/Project.hpp>
#include <TinyEngine/World/World.hpp>

namespace TinyEngine
{
	class ApplicationDelegate
	{
	public:
		ApplicationDelegate() = default;
		virtual ~ApplicationDelegate() = default;

	public:
		virtual void OnInit() {}
		virtual void OnDeinit() {}
	};

	class Application final : public Singleton<Application>
	{
	public:
		Application() = default;
		~Application() = default;

	public:
		Application& Init(int argc, char* argv[], const RenderWindowSettings& windowSettings, ApplicationDelegateUniquePtr&& delegate);

	public:
		void Execute();

		void LoggerSaveToFile();
		void Close();

	public:
		DebugPtr GetDebug();
		LoggerPtr GetLogger();
		RenderPtr GetRender();
		GuiPtr GetGui();
		FactoryPtr GetFactory();
		AssetsPtr GetAssets();
		FileSystemPtr GetFileSystem();
		Project& GetProject() { return _project; }
		const Project& GetConstProject() const { return _project; }
		World& GetWorld() { return _world; }
		const World& GetConstWorld() const { return _world; }

	private:
		void OnInit();
		void OnDeinit();

		void OnProcess();
		void OnUpdate();

	private:
		ApplicationDelegateUniquePtr _delegate;
		Project _project;
		World _world;
	};
}

#endif // _APPLICATION_HEADER_
