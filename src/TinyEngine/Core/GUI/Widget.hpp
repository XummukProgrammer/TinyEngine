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
		virtual void Init() {}
		virtual void Deinit() {}

		void Draw();

		void SetName(std::string_view name) { _name = name; }
		const std::string& GetName() const { return _name; }

		void MakeView(ViewType type);
		void SetView(std::unique_ptr<IWidgetView>&& view);
		IWidgetView* GetView() const { return _view.get(); }

	protected:
		virtual std::unique_ptr<IWidgetView> MakeImGUIView() const = 0;

	private:
		std::string _name;
		std::unique_ptr<IWidgetView> _view;
	};
}

#endif // _WIDGET_HEADER_
