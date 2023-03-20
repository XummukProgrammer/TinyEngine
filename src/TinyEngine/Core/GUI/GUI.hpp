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
			ImGui
		};

	public:
		GUI() = default;
		~GUI() = default;

	public:
		void Init();
		void Deinit();
		void Draw();

		Window* GetMainWindow() const;
		MenuBar* GetMenuBar() const;

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

	public:
		static WidgetsContainerType ViewToContainerType(Widget::ViewType widgetType);

	private:
		WidgetsLayersContainer* GetContainerByViewType(Widget::ViewType viewType) const;

	private:
		std::map<WidgetsContainerType, std::unique_ptr<WidgetsLayersContainer>> _widgetsLayersContainers;
		Window* _mainWindow = nullptr;
		MenuBar* _menuBar = nullptr;
	};

	template<typename T>
	T* GUI::MakeWidget(std::string_view widgetName, Widget::ViewType widgetType, WidgetLayerType layerType, const Widget::CustomMakeViewCallback& makeCallback)
	{
		return GetContainerByViewType(widgetType)->MakeWidget<T>(widgetName, widgetType, layerType, makeCallback);
	}

	template<typename T>
	T* GUI::MakeWidget(std::string_view widgetName, Widget::ViewType widgetType, const Widget::CustomMakeViewCallback& makeCallback)
	{
		return GetContainerByViewType(widgetType)->MakeWidget<T>(widgetName, widgetType, makeCallback);
	}

	template<typename T>
	T* GUI::MakePopup(std::string_view widgetName, Widget::ViewType widgetType, const Widget::CustomMakeViewCallback& makeCallback)
	{
		return GetContainerByViewType(widgetType)->MakePopup<T>(widgetName, widgetType, makeCallback);
	}

	template<typename T>
	T* GUI::GetWidget(std::string_view widgetName, Widget::ViewType widgetType) const
	{
		return GetContainerByViewType(widgetType)->GetWidget<T>(widgetName, widgetType);
	}

	template<typename T>
	T* GUI::GetBackWidget(Widget::ViewType widgetType) const
	{
		return GetContainerByViewType(widgetType)->GetBackWidget<T>(widgetType);
	}
}

#endif // _GUI_HEADER_
