#ifndef _GUI_PROJECT_WIDGET_HEADER_
#define _GUI_PROJECT_WIDGET_HEADER_

#include <TinyEngine/Gui/Widgets/GuiWindowWidget.hpp>

namespace TinyEngine
{
	class GuiProjectWidget final : public GuiWindowWidget
	{
	public:
		GuiProjectWidget() = default;
		~GuiProjectWidget() = default;

	public:
		static GuiProjectWidgetSharedPtr Create();
	};
}

#endif // _GUI_PROJECT_WIDGET_HEADER_
