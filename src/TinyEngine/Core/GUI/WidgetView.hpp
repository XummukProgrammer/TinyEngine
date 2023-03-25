#ifndef _WIDGET_VIEW_HEADER_
#define _WIDGET_VIEW_HEADER_

namespace TinyEngine
{
	class Widget;

	class IWidgetView
	{
	public:
		IWidgetView() = default;
		virtual ~IWidgetView() = default;

	public:
		virtual void OnInit() {}
		virtual void OnDeinit() {}

		virtual void OnDraw() = 0;

		virtual void OnActive() {}
		virtual void OnDeactive() {}

		virtual void OnShow() {}
		virtual void OnHide() {}

	public:
		void SetWidget(Widget* widget);
		Widget* GetWidget() const;

	private:
		Widget* _widget = nullptr;
	};
}

#endif // _WIDGET_VIEW_HEADER_
