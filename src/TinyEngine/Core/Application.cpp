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
	_windowUpdateListener.setOnSenderCallback(std::bind(&CApplication::onUpdate, this, std::placeholders::_1));
	_windowRef.get().getUpdateSender().addListener(_windowUpdateListener);
}

void CApplication::destroy()
{ 
	_windowRef.get().destroy();
}

void CApplication::onUpdate(const IWindow::CUpdateEvent& updateEvent)
{
}

}
