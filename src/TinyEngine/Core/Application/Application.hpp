#ifndef _APPLICATION_HEADER_
#define _APPLICATION_HEADER_

#include <TinyEngine/Core/Application/Context.hpp>
#include <raylib-cpp.hpp>

namespace TinyEngine
{
	class Application
	{
	public:
		void SetContext(Context& context) { _context = context; }
		const Context& GetContext() const { return _context; }
		Context& GetRefContext() { return _context; }

		void Load();
		void Create();
		void Run();
		void Stop();

	private:
		Context _context;
		RWindow _window;
	};

	void StartApp(int argc, char** argv);
}

#endif // _APPLICATION_HEADER_
