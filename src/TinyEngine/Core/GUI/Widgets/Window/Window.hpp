#ifndef _WINDOW_HEADER_
#define _WINDOW_HEADER_

#include <TinyEngine/Core/GUI/WidgetsLayersContainer.hpp>

namespace TinyEngine
{
	class Window final : public Widget
	{
	public:
		Window() = default;
		~Window() = default;

	public:
		virtual void OnInit() override;
		virtual void OnDeinit() override;

		virtual void OnDraw() override;

	public:
		const WidgetsLayersContainer& GetWidgetsContainer() const { return _widgetsLayersContainer; }
		WidgetsLayersContainer& GetRefWidgetsContainer() { return _widgetsLayersContainer; }

		void SetTitle(std::string_view title);

	private:
		virtual std::unique_ptr<IWidgetView> MakeImGUIView() const override;

	private:
		WidgetsLayersContainer _widgetsLayersContainer;
	};
}

#endif // _WINDOW_HEADER_
