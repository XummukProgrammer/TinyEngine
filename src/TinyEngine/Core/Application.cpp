#include "Application.hpp"
#include <TinyEngine/Graphics/Graphics.hpp>

namespace te
{

void CApplication::exec()
{ 
	init();

	_context.windowRef.get().exec();

	deinit();
}

void CApplication::init()
{ 
	_context.windowRef.get().create();
}

void CApplication::deinit()
{ 
	_context.windowRef.get().destroy();
}

}
