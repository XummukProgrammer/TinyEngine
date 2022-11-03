#ifndef _GUI_PROJECT_WIDGET_HEADER_
#define _GUI_PROJECT_WIDGET_HEADER_

#include <TinyEngine/Core/Gui/Widgets/GuiWindowWidget.hpp>

namespace TinyEngine
{
	class GuiProjectWidget final : public GuiWindowWidget
	{
	public:
		GuiProjectWidget() = default;
		~GuiProjectWidget() = default;

	public:
		static GuiProjectWidgetSharedPtr Create();

	public:
		void Load();

	private:
		void OnLoad();

	private:
		GuiInputTextWidgetSharedPtr _loadProjectFileWidget;
	};
}

#endif // _GUI_PROJECT_WIDGET_HEADER_
