#ifndef _GUI_HEADER_
#define _GUI_HEADER_

#include <TinyEngine/Core/GUI/WidgetsLayersContainer.hpp>

#include <map>
#include <memory>

namespace TinyEngine
{
	class Window;
	class MenuBar;

	class GUI final
	{
	public:
		enum class WidgetsContainerType
		{
			ImGUIWidgets,
			ImGUIPopups
		};

	public:
		GUI() = default;
		~GUI() = default;

	public:
		void Init();
		void Deinit();
		void Draw();

		Window* GetMainImGUIWindow() const;
		MenuBar* GetImGUIMenuBar() const;

		template<typename T>
		T* MakeWidget(std::string_view widgetName, Widget::ViewType widgetType, WidgetLayerType layerType, const Widget::CustomMakeViewCallback& makeCallback = nullptr);

		template<typename T>
		T* MakeWidget(std::string_view widgetName, Widget::ViewType widgetType, const Widget::CustomMakeViewCallback& makeCallback = nullptr);

		template<typename T>
		T* MakePopup(std::string_view widgetName, Widget::ViewType widgetType, const Widget::CustomMakeViewCallback& makeCallback = nullptr);

		template<typename T>
		T* GetWidget(std::string_view widgetName, Widget::ViewType widgetType) const;

		template<typename T>
		T* GetBackWidget(Widget::ViewType widgetType) const;

		template<typename T>
		T* GetPopup(std::string_view widgetName, Widget::ViewType widgetType) const;

		template<typename T>
		T* GetBackPopup(Widget::ViewType widgetType) const;

	private:
		WidgetsLayersContainer* GetContainer(Widget::ViewType viewType, bool isWidgets) const;

	private:
		std::map<WidgetsContainerType, std::unique_ptr<WidgetsLayersContainer>> _widgetsLayersContainers;
		Window* _mainImGUIWindow = nullptr;
		MenuBar* _imGUIMenuBar = nullptr;
	};

	template<typename T>
	T* GUI::MakeWidget(std::string_view widgetName, Widget::ViewType widgetType, WidgetLayerType layerType, const Widget::CustomMakeViewCallback& makeCallback)
	{
		return GetContainer(widgetType, true)->MakeWidget<T>(widgetName, widgetType, layerType, makeCallback);
	}

	template<typename T>
	T* GUI::MakeWidget(std::string_view widgetName, Widget::ViewType widgetType, const Widget::CustomMakeViewCallback& makeCallback)
	{
		return GetContainer(widgetType, true)->MakeWidget<T>(widgetName, widgetType, makeCallback);
	}

	template<typename T>
	T* GUI::MakePopup(std::string_view widgetName, Widget::ViewType widgetType, const Widget::CustomMakeViewCallback& makeCallback)
	{
		return GetContainer(widgetType, false)->MakePopup<T>(widgetName, widgetType, makeCallback);
	}

	template<typename T>
	T* GUI::GetWidget(std::string_view widgetName, Widget::ViewType widgetType) const
	{
		return GetContainer(widgetType, true)->GetWidget<T>(widgetName, widgetType);
	}

	template<typename T>
	T* GUI::GetBackWidget(Widget::ViewType widgetType) const
	{
		return GetContainer(widgetType, true)->GetBackWidget<T>(widgetType);
	}

	template<typename T>
	T* GUI::GetPopup(std::string_view widgetName, Widget::ViewType widgetType) const
	{
		return GetContainer(widgetType, false)->GetWidget<T>(widgetName, widgetType);
	}

	template<typename T>
	T* GUI::GetBackPopup(Widget::ViewType widgetType) const
	{
		return GetContainer(widgetType, false)->GetBackWidget<T>(widgetType);
	}
}

#endif // _GUI_HEADER_
