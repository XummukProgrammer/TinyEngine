#ifndef _WINDOW_IMGUI_VIEW_HEADER_
#define _WINDOW_IMGUI_VIEW_HEADER_

#include <TinyEngine/Core/GUI/Widgets/Window/IWindowView.hpp>

namespace TinyEngine
{
	class WindowImGUIView final : public IWindowView
	{
	public:
		WindowImGUIView() = default;
		~WindowImGUIView() = default;

	public:
		virtual void Begin() override;
		virtual void End() override;

		virtual void OnActive() override;
		virtual void OnDeactive() override;

		virtual void OnShow() override;
		virtual void OnHide() override;

		virtual void OnDraw() override {}

		virtual void SetTitle(std::string_view title) override;

	private:
		std::string _title;
	};
}

#endif // _WINDOW_IMGUI_VIEW_HEADER_
