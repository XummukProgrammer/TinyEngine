#ifndef _TINY_ENGINE_APPLICATION_HEADER_
#define _TINY_ENGINE_APPLICATION_HEADER_

#include "Paths.hpp"

#include <TinyEngine/Events/Events.hpp>
#include <TinyEngine/Graphics/Graphics.hpp>
#include <TinyEngine/Debug/Debug.hpp>

#include <functional>
#include <memory>

namespace TE
{

class CApplication final
{
public:
	using IWindowPtr = std::unique_ptr<IWindow>;
	using CWindowUpdateListener = CListener<IWindow::CUpdateEvent>;
	using CWindowDrawListener = CListener<IWindow::CDrawEvent>;

public:
	CApplication(int argc, char* argv[]);
	~CApplication() = default;

public:
	CPaths& getPaths() { return _paths; }
	CLog& getLog() { return _log; }
	CDebugAdapter& getDebugAdapter() { return _debugAdapter; }

	void setWindow(IWindowPtr window);

	void exec();

private:
	void init();
	void destroy();

private:
	void onUpdate(const IWindow::CUpdateEvent& updateEvent);
	void onDraw(const IWindow::CDrawEvent& drawEvent);

private:
	IWindowPtr _windowPtr;
	CWindowUpdateListener _windowUpdateListener;
	CWindowDrawListener _windowDrawListener;

	CPaths _paths;
	CLog _log;
	CDebugAdapter _debugAdapter;
};

}

#endif // _TINY_ENGINE_APPLICATION_HEADER_
