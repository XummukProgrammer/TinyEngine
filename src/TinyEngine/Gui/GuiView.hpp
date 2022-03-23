#ifndef _GUI_VIEW_HEADER_
#define _GUI_VIEW_HEADER_

#include "GuiModel.hpp"

namespace TinyEngine
{
	class GuiView
	{
	public:
		GuiView() = default;
		virtual ~GuiView() = default;

	public:
		virtual void OnGuiRenderer(const GuiModel& model) = 0;
	};
}

#endif // _GUI_VIEW_HEADER_
