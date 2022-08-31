#ifndef _GUI_VISITOR_HEADER_
#define _GUI_VISITOR_HEADER_

#include <TinyEngine/Gui/Widgets/GuiButtonWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiInputTextWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiLabelWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiMenuBarWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiProjectWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiWindowWidget.hpp>

#include <string>

namespace TinyEngine
{
	template<typename T>
	class GuiVisitor
	{
	public:
		static void AddWidget(GuiWidgetContainerPtr container, std::string_view name, std::string_view description, T* value)
		{
		}
	};

	template<>
	class GuiVisitor<std::string>
	{
	public:
		static void AddWidget(GuiWidgetContainerPtr container, std::string_view name, std::string_view description, std::string* value)
		{
			auto widget = GuiInputTextWidget::Create(name, [value](std::string_view text)
			{
				*value = text;
			});
			
			container->AddWidget(name, widget);
		}
	};
}

#endif // _GUI_VISITOR_HEADER_
