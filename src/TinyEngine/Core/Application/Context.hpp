#ifndef _CONTEXT_HEADER_
#define _CONTEXT_HEADER_

#include <string>

namespace TinyEngine
{
	class Context
	{
	public:
		void SetArgc(int argc) { _argc = argc; }
		int GetArgc() const { return _argc; }

		void SetArgv(char** argv) { _argv = argv; }
		char** GetArgv() const { return _argv; }

		void SetScreenWidth(int screenWidth) { _screenWidth = screenWidth; }
		int GetScreenWidth() const { return _screenWidth; }

		void SetScreenHeight(int screenHeight) { _screenHeight = screenHeight; }
		int GetScreenHeight() const { return _screenHeight; }

		void SetWindowTitle(std::string_view windowTitle) { _windowTitle = windowTitle; }
		const std::string& GetWindowTitle() const { return _windowTitle; }

	private:
		int _argc;
		char** _argv;
		int _screenWidth;
		int _screenHeight;
		std::string _windowTitle;
	};
}

#endif // _CONTEXT_HEADER_
