#ifndef _GUI_HEADER_
#define _GUI_HEADER_

#include <TinyEngine/Core/GUI/WidgetsLayersContainer.hpp>

namespace TinyEngine
{
	class Window;
	class MenuBar;

	class GUI final
	{
	public:
		GUI() = default;
		~GUI() = default;

	public:
		void Init();
		void Deinit();

		Window* GetMainWindow() const;
		MenuBar* GetMenuBar() const;

		template<typename T>
		T* MakeWidget(std::string_view widgetName, Widget::ViewType widgetType, WidgetLayerType layerType, const Widget::CustomMakeViewCallback& makeCallback = nullptr);

		template<typename T>
		T* MakeWidget(std::string_view widgetName, Widget::ViewType widgetType, const Widget::CustomMakeViewCallback& makeCallback = nullptr);

		template<typename T>
		T* MakePopup(std::string_view widgetName, Widget::ViewType widgetType, const Widget::CustomMakeViewCallback& makeCallback = nullptr);

	public:
		const WidgetsLayersContainer& GetImGUIWidgetsContainer() const { return _imGUIWidgetsLayersContainer; }
		WidgetsLayersContainer& GetRefImGUIWidgetsContainer() { return _imGUIWidgetsLayersContainer; }

	private:
		WidgetsLayersContainer _imGUIWidgetsLayersContainer;
		Window* _mainWindow = nullptr;
		MenuBar* _menuBar = nullptr;
	};

	template<typename T>
	T* GUI::MakeWidget(std::string_view widgetName, Widget::ViewType widgetType, WidgetLayerType layerType, const Widget::CustomMakeViewCallback& makeCallback)
	{
		switch (widgetType)
		{
		case Widget::ViewType::ImGUI:
			return _imGUIWidgetsLayersContainer.MakeWidget<T>(widgetName, widgetType, layerType, makeCallback);
		default:
			break;
		}

		return nullptr;
	}

	template<typename T>
	T* GUI::MakeWidget(std::string_view widgetName, Widget::ViewType widgetType, const Widget::CustomMakeViewCallback& makeCallback)
	{
		switch (widgetType)
		{
		case Widget::ViewType::ImGUI:
			return _imGUIWidgetsLayersContainer.MakeWidget<T>(widgetName, widgetType, makeCallback);
		default:
			break;
		}

		return nullptr;
	}

	template<typename T>
	T* GUI::MakePopup(std::string_view widgetName, Widget::ViewType widgetType, const Widget::CustomMakeViewCallback& makeCallback)
	{
		switch (widgetType)
		{
		case Widget::ViewType::ImGUI:
			return _imGUIWidgetsLayersContainer.MakePopup<T>(widgetName, widgetType, makeCallback);
		default:
			break;
		}

		return nullptr;
	}
}

#endif // _GUI_HEADER_
