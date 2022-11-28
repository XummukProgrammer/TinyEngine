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

		void OnRegisterFactory();
		void OnLoadGlobalContext();
		void OnLoadGui();

		void OnOpenProject();
		void OnSaveProject();
		void OnClose();

		void OnCreateAssetFile();

		void OnOpenProjectProperties();
		void OnOpenAssetFileProperties();
		
		void OnOpenFileBrowserHandler(EventPtr event);
		void OnSaveFileBrowserHandler(EventPtr event);

	private:
		Project _project;
		World _world;
		ConditionContext _globalContext;
		bool _isClose = false;
		bool _isOpenProjectFile = false;
		std::string _projectFilePath;

		EventSubscriberSharedPtr _fileBrowserOpenFileSubscriber;
		EventSubscriberSharedPtr _fileBrowserSaveFileSubscriber;

	private:
		static inline const std::string OPEN_PROJECT_SOURCE = "OpenProject";
		static inline const std::string CREATE_ASSET_SOURCE = "CreateAsset";
	};
}

#endif // _APPLICATION_HEADER_
