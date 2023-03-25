#ifndef _I_WINDOW_IMGUI_VIEW_HEADER_
#define _I_WINDOW_IMGUI_VIEW_HEADER_

#include <TinyEngine/Core/GUI/WidgetView.hpp>

#include <string>

namespace TinyEngine
{
	class IWindowView : public IWidgetView
	{
	public:
		IWindowView() = default;
		virtual ~IWindowView() = default;

	public:
		virtual bool TryBegin() = 0;
		virtual void End() = 0;
	};
}

#endif // _I_WINDOW_IMGUI_VIEW_HEADER_
