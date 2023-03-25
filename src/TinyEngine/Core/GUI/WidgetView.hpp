#ifndef _WIDGET_VIEW_HEADER_
#define _WIDGET_VIEW_HEADER_

namespace TinyEngine
{
	class Widget;

	class IWidgetView
	{
	public:
		enum class ViewType
		{
			ImGUI
		};

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

		void SetType(ViewType type) { _type = type; }
		ViewType GetType() const { return _type; }

	private:
		Widget* _widget = nullptr;
		ViewType _type;
	};
}

#endif // _WIDGET_VIEW_HEADER_
