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
		
		enum class WidgetsContainerAction
		{
			Widgets,
			Popups
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
		T* MakeWidget(std::string_view widgetName, IWidgetView::ViewType widgetType);

		template<typename T>
		T* MakePopup(std::string_view widgetName, IWidgetView::ViewType widgetType);

		template<typename T>
		T* GetWidget(std::string_view widgetName, IWidgetView::ViewType widgetType) const;

		template<typename T>
		T* GetBackWidget(IWidgetView::ViewType widgetType) const;

		template<typename T>
		T* GetPopup(std::string_view widgetName, IWidgetView::ViewType widgetType) const;

		template<typename T>
		T* GetBackPopup(IWidgetView::ViewType widgetType) const;

		void SetImGUIOpenPopup(std::string_view widgetName);

	private:
		WidgetsLayerContainer* GetContainer(IWidgetView::ViewType viewType, WidgetsContainerAction action) const;

		void TryOpenPopup();

	private:
		std::map<WidgetsContainerType, std::unique_ptr<WidgetsLayerContainer>> _widgetsLayersContainers;
		Window* _mainImGUIWindow = nullptr;
		MenuBar* _imGUIMenuBar = nullptr;
		std::string _imGUIOpenPopup;
	};

	template<typename T>
	T* GUI::MakeWidget(std::string_view widgetName, IWidgetView::ViewType widgetType)
	{
		return GetContainer(widgetType, WidgetsContainerAction::Widgets)->MakeWidget<T>(widgetName, widgetType);
	}

	template<typename T>
	T* GUI::MakePopup(std::string_view widgetName, IWidgetView::ViewType widgetType)
	{
		auto widget = GetContainer(widgetType, WidgetsContainerAction::Popups)->MakeWidget<T>(widgetName, widgetType);
		widget->SetTitle(widgetName);
		return widget;
	}

	template<typename T>
	T* GUI::GetWidget(std::string_view widgetName, IWidgetView::ViewType widgetType) const
	{
		return GetContainer(widgetType, WidgetsContainerAction::Widgets)->GetWidget<T>(widgetName);
	}

	template<typename T>
	T* GUI::GetBackWidget(IWidgetView::ViewType) const
	{
		return GetContainer(widgetType, WidgetsContainerAction::Widgets)->GetBackWidget<T>(widgetType);
	}

	template<typename T>
	T* GUI::GetPopup(std::string_view widgetName, IWidgetView::ViewType) const
	{
		return GetContainer(widgetType, WidgetsContainerAction::Popups)->GetWidget<T>(widgetName);
	}

	template<typename T>
	T* GUI::GetBackPopup(IWidgetView::ViewType) const
	{
		return GetContainer(widgetType, WidgetsContainerAction::Popups)->GetBackWidget<T>(widgetType);
	}
}

#endif // _GUI_HEADER_
