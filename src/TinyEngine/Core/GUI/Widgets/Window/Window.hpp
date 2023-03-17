#ifndef _WINDOW_HEADER_
#define _WINDOW_HEADER_

#include <TinyEngine/Core/GUI/WidgetsContainer.hpp>

namespace TinyEngine
{
	class Window final : public Widget
	{
	public:
		Window() = default;
		~Window() = default;

	public:
		virtual void OnDraw() override;

	public:
		const WidgetsContainer& GetWidgetsContainer() const { return _widgetsContainer; }
		WidgetsContainer& GetRefWidgetsContainer() { return _widgetsContainer; }

		void SetTitle(std::string_view title);

	private:
		virtual std::unique_ptr<IWidgetView> MakeImGUIView() const override;

	private:
		WidgetsContainer _widgetsContainer;
	};
}

#endif // _WINDOW_HEADER_
