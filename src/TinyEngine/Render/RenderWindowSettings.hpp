#ifndef _RENDER_WINDOW_SETTINGS_HEADER_
#define _RENDER_WINDOW_SETTINGS_HEADER_

#include <TinyEngine/Core/Constants.hpp>

#include <string>

namespace TinyEngine
{
	struct RenderWindowSettings
	{
		RenderType renderType;
		std::string title;
		int width;
		int height;
		int maxFramerate;
	};
};

#endif // _RENDER_WINDOW_SETTINGS_HEADER_
