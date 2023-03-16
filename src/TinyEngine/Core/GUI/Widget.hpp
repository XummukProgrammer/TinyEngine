#ifndef _WIDGET_HEADER_
#define _WIDGET_HEADER_

#include <TinyEngine/Core/GUI/WidgetView.hpp>

#include <string>
#include <memory>

namespace TinyEngine
{
	class Widget
	{
	public:
		enum class ViewType
		{
			ImGUI
		};

	public:
		Widget() = default;
		virtual ~Widget() = default;

	public:
		virtual void OnInit() {}
		virtual void OnDeinit() {}

		virtual void OnActive() {}
		virtual void OnDeactive() {}

		virtual void OnShow() {}
		virtual void OnHide() {}

		virtual void OnDraw();

		void SetName(std::string_view name) { _name = name; }
		const std::string& GetName() const { return _name; }

		void MakeView(ViewType type);
		ViewType GetViewType() const { return _viewType; }
		void SetView(std::unique_ptr<IWidgetView>&& view);
		IWidgetView* GetView() const { return _view.get(); }

		void SetActive(bool isActive);
		bool IsActive() const { return _isActive; }

		void SetVisible(bool isVisible);
		bool IsVisible() const { return _isVisible; }

	protected:
		virtual std::unique_ptr<IWidgetView> MakeImGUIView() const = 0;

	private:
		std::string _name;
		std::unique_ptr<IWidgetView> _view;
		ViewType _viewType;
		bool _isActive = true;
		bool _isVisible = true;
	};
}

#endif // _WIDGET_HEADER_
