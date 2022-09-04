#ifndef _GUI_VISITOR_HEADER_
#define _GUI_VISITOR_HEADER_

#include <TinyEngine/Gui/GuiWidgetContainer.hpp>
#include <TinyEngine/Gui/Widgets/GuiButtonWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiInputTextWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiLabelWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiCheckboxWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiInputNumberWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiInputFloatWidget.hpp>

#include <string>
#include <vector>

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
			auto widget = GuiInputNumberWidget::Create(name, *value, [value](int val)
			{
				*value = val;
			});

			container->AddWidget(name, widget);
		}
	};

	template<>
	class GuiVisitor<float>
	{
	public:
		static void AddWidget(GuiWidgetContainerPtr container, std::string_view name, std::string_view description, float* value)
		{
			auto widget = GuiInputFloatWidget::Create(name, *value, [value](float val)
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

	template<typename T>
	class GuiVisitor<std::vector<T>>
	{
	public:
		static void AddWidget(GuiWidgetContainerPtr container, std::string_view name, std::string_view description, std::vector<T>* value)
		{
		}
	};
}

#endif // _GUI_VISITOR_HEADER_
