#include "Application.hpp"
#include <TinyEngine/Graphics/Graphics.hpp>

namespace TE
{

CApplication::CApplication(int argc, char* argv[])
	: _paths(argc, argv)
	, _debugAdapter(_paths, _log)
{
}

void CApplication::exec()
{ 
	init();

	_debugAdapter.sendInfoMessage("[CApplication] exec");

	_windowPtr->exec();

	destroy();
}

void CApplication::setWindow(IWindowPtr window)
{ 
	_windowPtr = std::move(window);
}

void CApplication::init()
{ 
	_debugAdapter.sendInfoMessage("[CApplication] init");

	_windowUpdateListenerPtr = CWindowUpdateListener::create(std::bind(&CApplication::onUpdate, this, std::placeholders::_1));
	_windowPtr->getUpdateSender().addListener(_windowUpdateListenerPtr);

	_windowDrawListenerPtr = CWindowDrawListener::create(std::bind(&CApplication::onDraw, this, std::placeholders::_1));
	_windowPtr->getDrawSender().addListener(_windowDrawListenerPtr);
}

void CApplication::destroy()
{ 
	_debugAdapter.sendInfoMessage("[CApplication] destroy");

	_log.dumpAllLogMessages(_paths);

	_windowUpdateListenerPtr.reset();
	_windowDrawListenerPtr.reset();

	_windowPtr->destroy();
	_windowPtr.reset();
}

void CApplication::onUpdate(const IWindow::CUpdateEvent& updateEvent)
{
}

void CApplication::onDraw(const IWindow::CDrawEvent& drawEvent)
{
}

}
