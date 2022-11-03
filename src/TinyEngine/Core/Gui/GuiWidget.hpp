#ifndef _GUI_WIDGET_HEADER_
#define _GUI_WIDGET_HEADER_

#include <TinyEngine/Core/Render/Render.hpp>

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
		virtual void Draw(float deltaTime) {}

	public:
		void SetIsActive(bool isActive) { _isActive = isActive; }
		bool IsActive() const { return _isActive; }

	private:
		bool _isActive = true;
	};
}

#endif // _GUI_WIDGET_HEADER_
