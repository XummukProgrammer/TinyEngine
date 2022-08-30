#ifndef _GUI_WIDGET_HEADER_
#define _GUI_WIDGET_HEADER_

#include <TinyEngine/Render/Render.hpp>

#include "imgui.h"
#include "imgui_internal.h"

namespace TinyEngine
{
	class GuiWidget
	{
	public:
		GuiWidget() = default;
		~GuiWidget() = default;

	public:
		virtual void Draw(float deltaTime, IRenderWindowSharedPtr renderWindowPtr) {}
	};
}

#endif // _GUI_WIDGET_HEADER_
