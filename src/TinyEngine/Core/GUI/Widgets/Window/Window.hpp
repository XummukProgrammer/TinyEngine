﻿#ifndef _WINDOW_HEADER_
#define _WINDOW_HEADER_

#include <TinyEngine/Core/GUI/WidgetsLayersContainer.hpp>

namespace TinyEngine
{
	class Window : public Widget
	{
	public:
		Window() = default;
		virtual ~Window() = default;

	public:
		virtual void OnInit() override;
		virtual void OnDeinit() override;

		virtual void OnDraw() override;

	public:
		void SetTitle(std::string_view title);
		const std::string& GetTitle() const { return _title; }

		template<typename T>
		T* MakeWidget(std::string_view widgetName);

		template<typename T>
		T* GetWidget(std::string_view widgetName) const;

		template<typename T>
		T* GetBackWidget() const;

	protected:
		const WidgetsLayerContainer& GetWidgetsLayersContainer() const { return _widgetsLayersContainer; }
		WidgetsLayerContainer& GetRefWidgetsLayersContainer() { return _widgetsLayersContainer; }

	private:
		virtual std::unique_ptr<IWidgetView> MakeImGUIView() const override;

	private:
		WidgetsLayerContainer _widgetsLayersContainer;
		std::string _title;
	};

	template<typename T>
	T* Window::MakeWidget(std::string_view widgetName)
	{
		return _widgetsLayersContainer.MakeWidget<T>(widgetName, GetViewType());
	}

	template<typename T>
	T* Window::GetWidget(std::string_view widgetName) const
	{
		return _widgetsLayersContainer.GetWidget<T>(GetViewType(), widgetName);
	}

	template<typename T>
	T* Window::GetBackWidget() const
	{
		return _widgetsLayersContainer.GetBackWidget<T>(GetViewType());
	}

	class MainImGUIWindow final : public Window
	{
	public:
		MainImGUIWindow() = default;
		~MainImGUIWindow() = default;

	protected:
		virtual std::unique_ptr<IWidgetView> MakeImGUIView() const override;
	};
}

#endif // _WINDOW_HEADER_
