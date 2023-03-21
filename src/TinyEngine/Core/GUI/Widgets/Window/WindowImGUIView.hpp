#ifndef _WINDOW_IMGUI_VIEW_HEADER_
#define _WINDOW_IMGUI_VIEW_HEADER_

#include <TinyEngine/Core/GUI/Widgets/Window/IWindowView.hpp>

namespace TinyEngine
{
	class WindowImGUIView : public IWindowView
	{
	public:
		WindowImGUIView() = default;
		virtual ~WindowImGUIView() = default;

	public:
		virtual bool TryBegin() override;
		virtual void End() override;

		virtual void OnDraw() override {}

		virtual void SetTitle(std::string_view title) override;

	private:
		std::string _title;
	};

	class MainWindowImGUIView final : public WindowImGUIView
	{
	public:
		MainWindowImGUIView() = default;
		~MainWindowImGUIView() = default;

	public:
		virtual bool TryBegin() override;
		virtual void End() override;
	};
}

#endif // _WINDOW_IMGUI_VIEW_HEADER_
