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

	_windowUpdateListener.setOnSenderCallback(std::bind(&CApplication::onUpdate, this, std::placeholders::_1));
	_windowPtr->getUpdateSender().addListener(_windowUpdateListener);

	_windowDrawListener.setOnSenderCallback(std::bind(&CApplication::onDraw, this, std::placeholders::_1));
	_windowPtr->getDrawSender().addListener(_windowDrawListener);
}

void CApplication::destroy()
{ 
	_debugAdapter.sendInfoMessage("[CApplication] destroy");

	_log.dumpAllLogMessages(_paths);

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
