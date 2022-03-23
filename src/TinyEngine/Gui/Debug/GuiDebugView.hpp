#ifndef _GUI_DEBUG_VIEW_HEADER_
#define _GUI_DEBUG_VIEW_HEADER_

#include <TinyEngine/Gui/GuiView.hpp>

namespace TinyEngine
{
	class GuiDebugView final : public GuiView
	{
	public:
		GuiDebugView() = default;
		~GuiDebugView() = default;

	public:
		void OnGuiRenderer(const GuiModel& model) override;
	};
}

#endif // _GUI_DEBUG_VIEW_HEADER_
