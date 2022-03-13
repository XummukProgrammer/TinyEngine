#ifndef _APPLICATION_HEADER_
#define _APPLICATION_HEADER_

#include <memory>

namespace TinyEngine::Core
{
	class Window;

	class Application final : public std::enable_shared_from_this<Application>
	{
	public:
		using WindowPtr = std::shared_ptr<Window>;

	public:
		Application(int argc, char** argv);
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
		int _argc = 0;
		char** _argv;

		WindowPtr _window;
	};
}

#endif // _APPLICATION_HEADER_
