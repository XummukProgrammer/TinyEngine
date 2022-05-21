#include "Application.hpp"
#include <TinyEngine/Graphics/Graphics.hpp>

namespace te
{

CApplication::CApplication(IWindowRef windowRef)
	: _windowRef(windowRef)
{}

void CApplication::exec()
{ 
	_windowRef.get().exec();
}

}
