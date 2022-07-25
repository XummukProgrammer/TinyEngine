﻿#ifndef _GUI_WIDGET_HEADER_
#define _GUI_WIDGET_HEADER_

#include <TinyEngine/Render/Render.hpp>

namespace TinyEngine
{
	class GuiWidget
	{
	public:
		GuiWidget() = default;
		~GuiWidget() = default;

	public:
		virtual void Draw(float deltaTime, IRenderWindowPtr renderWindowPtr) = 0;
	};
}

#endif // _GUI_WIDGET_HEADER_
