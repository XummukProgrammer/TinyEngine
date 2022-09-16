#ifndef _GUI_VISITOR_HEADER_
#define _GUI_VISITOR_HEADER_

#include <TinyEngine/Data/Meta/Class/MetaClass.hpp>
#include <TinyEngine/Gui/GuiWidgetContainer.hpp>
#include <TinyEngine/Gui/Widgets/GuiButtonWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiInputTextWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiLabelWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiCheckboxWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiInputNumberWidget.hpp>
#include <TinyEngine/Gui/Widgets/GuiInputFloatWidget.hpp>
#include <TinyEngine/Gui/Widgets/Containers/GuiInputVectorWidget.hpp>
#include <TinyEngine/Gui/Widgets/Containers/GuiInputMapWidget.hpp>
#include <TinyEngine/Gui/Widgets/Containers/GuiMetaClassWidget.hpp>
#include <TinyEngine/Gui/Widgets/Containers/GuiSharedPtrWidget.hpp>

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
			auto widget = GuiMetaClassWidget::Create(name);
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
}

#endif // _GUI_VISITOR_HEADER_
