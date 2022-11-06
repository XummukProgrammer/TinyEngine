#ifndef _APPLICATION_HEADER_
#define _APPLICATION_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Data/Singleton.hpp>
#include <TinyEngine/Core/Render/RenderWindowSettings.hpp>
#include <TinyEngine/Core/Project.hpp>

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
		Project& GetProject() { return _project; }
		const Project& GetConstProject() const { return _project; }

		void UpdateWorld();

	private:
		void OnInit();
		void OnDeinit();

		void OnProcess();
		void OnUpdate();

	private:
		ApplicationDelegateUniquePtr _delegate;
		Project _project;
	};
}

#endif // _APPLICATION_HEADER_
