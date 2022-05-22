#include "Application.hpp"
#include <TinyEngine/Graphics/Graphics.hpp>

namespace TE
{

CApplication::CApplication(IWindowRef windowRef)
	: _windowRef(windowRef)
{
	init();
}

void CApplication::exec()
{ 
	_windowRef.get().exec();

	destroy();
}

void CApplication::init()
{ 
	auto& window = _windowRef.get();

	_windowUpdateListener.setOnSenderCallback(std::bind(&CApplication::onUpdate, this, std::placeholders::_1));
	window.getUpdateSender().addListener(_windowUpdateListener);

	_windowDrawListener.setOnSenderCallback(std::bind(&CApplication::onDraw, this, std::placeholders::_1));
	window.getDrawSender().addListener(_windowDrawListener);
}

void CApplication::destroy()
{ 
	_windowRef.get().destroy();
}

void CApplication::onUpdate(const IWindow::CUpdateEvent& updateEvent)
{
}

void CApplication::onDraw(const IWindow::CDrawEvent& drawEvent)
{
}

}
