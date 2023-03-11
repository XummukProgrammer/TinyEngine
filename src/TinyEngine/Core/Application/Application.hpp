#ifndef _APPLICATION_HEADER_
#define _APPLICATION_HEADER_

#include <TinyEngine/Core/Application/Context.hpp>
#include <raylib-cpp.hpp>

namespace TinyEngine
{
	class Application
	{
	public:
		enum class State
		{
			NotInitialized,
			ProjectLoaded,
			Started
		};

	public:
		static Application& GetSingleton() { return _singleton; }

	public:
		void SetContext(Context& context) { _context = context; }
		const Context& GetContext() const { return _context; }
		Context& GetRefContext() { return _context; }

		void Load();
		void Create();
		void Run();
		void Stop();

		void ChangeState(State state);

	private:
		void OnInit();
		void OnDeinit();
		void OnUpdate();
		void OnDraw();

		void OnProjectLoaded();
		void OnStarted();

	private:
		Context _context;
		RWindow _window;
		State _state = State::NotInitialized;

	private:
		static Application _singleton;
	};

	void StartApp(int argc, char** argv);
}

#endif // _APPLICATION_HEADER_
