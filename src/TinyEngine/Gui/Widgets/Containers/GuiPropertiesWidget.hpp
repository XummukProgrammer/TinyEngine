#ifndef _GUI_PROPERTIES_WIDGET_HEADER_
#define _GUI_PROPERTIES_WIDGET_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Gui/Widgets/GuiWindowWidget.hpp>

namespace TinyEngine
{
	class GuiPropertiesWidget final : public GuiWindowWidget
	{
	public:
		GuiPropertiesWidget() = default;
		~GuiPropertiesWidget() = default;

	public:
		static GuiPropertiesWidgetSharedPtr Create();

	public:
		void InitFromMetaClass(MetaClassPtr metaClass);
		void Reset();
	};
}

#endif // _GUI_PROPERTIES_WIDGET_HEADER_
