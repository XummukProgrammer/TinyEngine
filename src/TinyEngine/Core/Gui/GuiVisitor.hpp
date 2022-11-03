#ifndef _GUI_VISITOR_HEADER_
#define _GUI_VISITOR_HEADER_

#include <TinyEngine/Core/Data/Meta/Class/MetaClass.hpp>
#include <TinyEngine/Core/Gui/GuiWidgetContainer.hpp>
#include <TinyEngine/Core/Gui/Widgets/GuiButtonWidget.hpp>
#include <TinyEngine/Core/Gui/Widgets/GuiInputTextWidget.hpp>
#include <TinyEngine/Core/Gui/Widgets/GuiLabelWidget.hpp>
#include <TinyEngine/Core/Gui/Widgets/GuiCheckboxWidget.hpp>
#include <TinyEngine/Core/Gui/Widgets/GuiInputNumberWidget.hpp>
#include <TinyEngine/Core/Gui/Widgets/GuiInputFloatWidget.hpp>
#include <TinyEngine/Core/Gui/Widgets/Containers/GuiInputVectorWidget.hpp>
#include <TinyEngine/Core/Gui/Widgets/Containers/GuiInputMapWidget.hpp>
#include <TinyEngine/Core/Gui/Widgets/Containers/GuiSharedPtrWidget.hpp>
#include <TinyEngine/Core/Gui/Widgets/GuiStringListBoxWidget.hpp>

#include <magic_enum.hpp>

#include <string>
#include <vector>
#include <map>
#include <memory>

namespace TinyEngine
{
	template<typename T>
	class GuiVisitor
	{
	public:
		static void AddWidget(GuiWidgetContainerPtr container, std::string_view name, std::string_view description, T* value)
		{
			if constexpr (std::is_base_of_v<MetaClass, T>)
			{
				GuiVisitor<MetaClass>::AddWidget(container, name, description, value);
			}
			else if constexpr (std::is_enum_v<T>)
			{
				GuiVisitorUniqueImpl::EnumAddWidget<T>(container, name, description, value);
			}
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
			auto widget = GuiInputTextWidget::Create(name, *value, [value](std::string_view text)
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
		static void AddWidget(GuiWidgetContainerPtr container, std::string_view name, std::string_view description, std::vector<T>* values)
		{
			auto widget = GuiInputVectorWidget::Create(name);

			widget->SetOnValueAddCallback([widget, values]()
			{
				values->push_back(T());
				auto& back = values->back();
				GuiVisitor<T>::AddWidget(widget.get(), std::to_string(static_cast<int>(values->size()) - 1), "", &back);
			});

			int index = 0;
			auto& valuesRef = *values;
			for (auto& value : valuesRef)
			{
				GuiVisitor<T>::AddWidget(widget.get(), std::to_string(index), "", &value);
				++index;
			}

			container->AddWidget(name, widget);
		}
	};

	template<typename K, typename V>
	class GuiVisitor<std::map<K, V>>
	{
	public:
		static void AddWidget(GuiWidgetContainerPtr container, std::string_view name, std::string_view description, std::map<K, V>* values)
		{
			auto widget = GuiInputMapWidget::Create(name);

			auto& valuesRef = *values;

			widget->SetOnValueAddCallback([widget, &valuesRef](std::string_view key)
			{
				valuesRef[std::string{key}] = V{};
				GuiVisitor<V>::AddWidget(widget.get(), key, "", &valuesRef[std::string{key}]);
			});

			for (auto& [ key, value ] : valuesRef)
			{
				GuiVisitor<V>::AddWidget(widget.get(), key, "", &value);
			}

			container->AddWidget(name, widget);
		}
	};

	template<>
	class GuiVisitor<MetaClass>
	{
	public:
		static void AddWidget(GuiWidgetContainerPtr container, std::string_view name, std::string_view description, MetaClass* value)
		{
			auto widget = GuiTreeContainerWidget::Create(name);
			value->AddGuiWidgetsToContainer(widget.get());
			container->AddWidget(name, widget);
		}
	};

	template<typename T>
	class GuiVisitor<std::shared_ptr<T>>
	{
	public:
		static void AddWidget(GuiWidgetContainerPtr container, std::string_view name, std::string_view description, std::shared_ptr<T>* value)
		{
			const bool isInited = value->get() != nullptr;
			auto& valueRef = *value;
			const auto& inheritorTypes = Factory::GetInstance()->GetInheritorTypes<T>();
			auto widget = GuiSharedPtrWidget::Create(name, isInited, {}, inheritorTypes);
			widget->SetOnInitCallback([&valueRef, widget](std::string_view type)
			{
				valueRef = Factory::GetInstance()->Create<T>(type);
				valueRef->AddGuiWidgetsToContainer(widget.get());

			});
			container->AddWidget(name, widget);
		}
	};

	class GuiVisitorUniqueImpl
	{
	public:
		template<typename T, typename = std::enable_if<std::is_enum_v<T>, bool>::type>
		static void EnumAddWidget(GuiWidgetContainerPtr container, std::string_view name, std::string_view description, T* value)
		{
			auto widget = GuiStringListBoxWidget::Create(name);
			widget->SetOnChangedCallback([value](std::string_view val)
			{
				*value = magic_enum::enum_cast<T>(val).value();
			});
				
			const auto enumNames = magic_enum::enum_names<T>();
			for (const auto& enumName : enumNames)
			{
				widget->AddItem(enumName);
			}

			const auto& enumName = magic_enum::enum_name(*value);
			int enumNumber = widget->GetNumberFromString(enumName);
			widget->SetCurrentItem(enumNumber);

			container->AddWidget(name, widget);
		}
	};
}

#endif // _GUI_VISITOR_HEADER_
