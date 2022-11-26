#ifndef _APPLICATION_HEADER_
#define _APPLICATION_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Data/Singleton.hpp>
#include <TinyEngine/Core/Render/RenderWindowSettings.hpp>
#include <TinyEngine/Core/Project.hpp>
#include <TinyEngine/Core/World/World.hpp>
#include <TinyEngine/Core/Conditions/ConditionContext.hpp>
#include <TinyEngine/Core/Event/EventSubscriber.hpp>

namespace TinyEngine
{
	class Application final : public Singleton<Application>
	{
	public:
		Application() = default;
		~Application() = default;

	public:
		void SetConsoleVars(int argc, char* argv[]);
		void SetWindowSettings(const RenderWindowSettings& windowSettings);

		void Execute();

		void LoggerSaveToFile();
		void Close();

	public:
		Project& GetProject() { return _project; }
		const Project& GetConstProject() const { return _project; }

		World& GetWorld() { return _world; }
		const World& GetConstWorld() const { return _world; }

		ConditionContext& GetGlobalContext() { return _globalContext; }
		const ConditionContext& GetConstGlobalContext() const { return _globalContext; }

	private:
		void OnInit();
		void OnDeinit();

		void OnProcess();
		void OnUpdate();

		void OnOpenProject();
		void OnSaveProject();
		void OnClose();

		void OnOpenProjectFile(EventPtr event);

	private:
		Project _project;
		World _world;
		ConditionContext _globalContext;
		bool _isClose = false;

		EventSubscriberSharedPtr _fileBrowserOpenFileSubscriber;
	};
}

#endif // _APPLICATION_HEADER_
