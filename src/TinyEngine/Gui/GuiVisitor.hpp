﻿#ifndef _GUI_VISITOR_HEADER_
#define _GUI_VISITOR_HEADER_

#include <TinyEngine/Gui/Widgets/GuiButtonWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiInputTextWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiLabelWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiMenuBarWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiProjectWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiWindowWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiCheckboxWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiInputNumber.hpp>

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
	class GuiVisitor<bool>
	{
	public:
		static void AddWidget(GuiWidgetContainerPtr container, std::string_view name, std::string_view description, bool* value)
		{
			auto widget = GuiCheckboxWidget::Create(name, *value, [value](bool flag)
			{
				*value = flag;
			});

			container->AddWidget(name, widget);
		}
	};

	template<>
	class GuiVisitor<int>
	{
	public:
		static void AddWidget(GuiWidgetContainerPtr container, std::string_view name, std::string_view description, int* value)
		{
			auto widget = GuiInputNumber::Create(name, *value, [value](int val)
			{
				*value = val;
			});

			container->AddWidget(name, widget);
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
