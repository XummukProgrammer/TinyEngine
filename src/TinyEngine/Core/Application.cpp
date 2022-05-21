#include "Application.hpp"
#include <TinyEngine/Graphics/Graphics.hpp>

namespace te
{

void CApplication::exec()
{ 
	_context.windowRef.get().exec();
}

}
