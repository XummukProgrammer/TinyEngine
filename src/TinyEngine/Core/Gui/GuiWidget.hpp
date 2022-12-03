#ifndef _GUI_WIDGET_HEADER_
#define _GUI_WIDGET_HEADER_

#include <TinyEngine/Core/Render/Render.hpp>

#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"

namespace TinyEngine
{
	class GuiWidget
	{
	public:
		GuiWidget() = default;
		~GuiWidget() = default;

	public:
		virtual void OnInit() {}
		virtual void OnDeinit() {}
		virtual void Draw(float deltaTime) {}

	public:
		void SetIsActive(bool isActive) { _isActive = isActive; }
		bool IsActive() const { return _isActive; }

		void SetIsRemove(bool isRemove) { _isRemove = isRemove; }
		bool IsRemove() const { return _isRemove; }

		bool IsValid() const { return IsActive() && !IsRemove(); }

	private:
		bool _isActive = true;
		bool _isRemove = false;
	};
}

#endif // _GUI_WIDGET_HEADER_
