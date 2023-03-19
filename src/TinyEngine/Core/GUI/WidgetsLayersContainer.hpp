﻿#ifndef _WIDGETS_LAYERS_CONTAINER_HEADER_
#define _WIDGETS_LAYERS_CONTAINER_HEADER_

#include <TinyEngine/Core/GUI/Widget.hpp>

#include <vector>
#include <memory>
#include <string>
#include <map>

namespace TinyEngine
{
	enum class WidgetLayerType
	{
		MainWindow,
		PopupWindows
	};

	class WidgetsLayerContainer final
	{
	public:
		WidgetsLayerContainer() = default;
		~WidgetsLayerContainer() = default;

	public:
		void Draw();

	public:
		void AddWidget(std::unique_ptr<Widget>&& widget);
		bool HasWidget(std::string_view name) const;
		Widget* GetWidget(std::string_view name) const;
		Widget* GetBackWidget() const;

	private:
		std::vector<std::unique_ptr<Widget>> _widgets;
	};

	class WidgetsLayersContainer final
	{
	public:
		WidgetsLayersContainer() = default;
		~WidgetsLayersContainer() = default;

	public:
		void Init();
		void Deinit();
		void Draw();

	public:
		WidgetsLayerContainer* GetContainer(WidgetLayerType type) const;

		template<typename T>
		T* MakeWidget(std::string_view widgetName, Widget::ViewType widgetType, WidgetLayerType layerType, const Widget::CustomMakeViewCallback& makeCallback = nullptr);

		template<typename T>
		T* MakeWidget(std::string_view widgetName, Widget::ViewType widgetType, const Widget::CustomMakeViewCallback& makeCallback = nullptr);

		template<typename T>
		T* MakePopup(std::string_view widgetName, Widget::ViewType widgetType, const Widget::CustomMakeViewCallback& makeCallback = nullptr);

	private:
		std::map<WidgetLayerType, std::unique_ptr<WidgetsLayerContainer>> _layers;
	};

	template<typename T>
	T* WidgetsLayersContainer::MakeWidget(std::string_view widgetName, Widget::ViewType widgetType, WidgetLayerType layerType, const Widget::CustomMakeViewCallback& makeCallback)
	{
		auto widget = std::make_unique<T>();

		widget->SetName(widgetName);
		widget->MakeView(widgetType, makeCallback);

		auto container = GetContainer(layerType);
		container->AddWidget(std::move(widget));
		return dynamic_cast<T*>(container->GetBackWidget());
	}

	template<typename T>
	T* WidgetsLayersContainer::MakeWidget(std::string_view widgetName, Widget::ViewType widgetType, const Widget::CustomMakeViewCallback& makeCallback)
	{
		return MakeWidget<T>(widgetName, widgetType, WidgetLayerType::MainWindow, makeCallback);
	}

	template<typename T>
	T* WidgetsLayersContainer::MakePopup(std::string_view widgetName, Widget::ViewType widgetType, const Widget::CustomMakeViewCallback& makeCallback)
	{
		return MakeWidget<T>(widgetName, widgetType, WidgetLayerType::PopupWindows, makeCallback);
	}
}

#endif // _WIDGETS_LAYERS_CONTAINER_HEADER_
