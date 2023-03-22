#ifndef _WINDOW_HEADER_
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
		T* MakeWidget(std::string_view widgetName, const Widget::CustomMakeViewCallback& makeCallback = nullptr);

		template<typename T>
		T* GetWidget(std::string_view widgetName) const;

		template<typename T>
		T* GetBackWidget() const;

	private:
		virtual std::unique_ptr<IWidgetView> MakeImGUIView() const override;

	protected:
		virtual ViewType GetViewType() const = 0;

	private:
		WidgetsLayerContainer _widgetsLayersContainer;
		std::string _title;
	};

	template<typename T>
	T* Window::MakeWidget(std::string_view widgetName, const Widget::CustomMakeViewCallback& makeCallback)
	{
		return _widgetsLayersContainer.MakeWidget<T>(widgetName, GetViewType(), makeCallback);
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

	class ImGUIWindow final : public Window
	{
	public:
		ImGUIWindow() = default;
		~ImGUIWindow() = default;

	protected:
		virtual ViewType GetViewType() const override { return ViewType::ImGUI; }
	};
}

#endif // _WINDOW_HEADER_
