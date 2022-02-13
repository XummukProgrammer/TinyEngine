#ifndef _APPLICATION_HEADER_
#define _APPLICATION_HEADER_

#include <memory>

namespace TinyEngine::Core
{
	class ApplicationDelegate
	{
	public:
		ApplicationDelegate() = default;
		virtual ~ApplicationDelegate() = default;

	public:
		virtual void OnPreInit() {}
		virtual void OnInit() {}

		virtual void OnDeinit() {}

		virtual void OnUpdate() {}
		virtual void OnDraw() {}
		virtual void OnEvent() {}
	};

	class Window;

	class Application final : public std::enable_shared_from_this<Application>
	{
	public:
		using WindowPtr = std::shared_ptr<Window>;

	public:
		Application(ApplicationDelegate& delegate, int argc, char** argv);
		~Application() = default;

	public:
		void Start();

	private:
		void OnPreInit();
		void OnInit();

		void OnDeinit();

		void OnExecute();

		void OnUpdate();
		void OnDraw();
		void OnEvent();

	private:
		ApplicationDelegate& _delegate;

		int _argc = 0;
		char** _argv;

		WindowPtr _window;
	};
}

#endif // _APPLICATION_HEADER_
