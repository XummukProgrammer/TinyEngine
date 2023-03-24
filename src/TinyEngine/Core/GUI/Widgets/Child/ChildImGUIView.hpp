#ifndef _CHILD_IMGUI_VIEW_HEADER_
#define _CHILD_IMGUI_VIEW_HEADER_

#include <TinyEngine/Core/GUI/Widgets/Child/IChildView.hpp>

namespace TinyEngine
{
	class ChildImGUIView final : public IChildView
	{
	public:
		ChildImGUIView() = default;
		~ChildImGUIView() = default;

	public:
		virtual void SetTitle(std::string_view title) override;

		virtual bool TryBegin() override;
		virtual void End() override;

		virtual void OnDraw() override {}

	private:
		std::string _title;
	};
}

#endif // _CHILD_IMGUI_VIEW_HEADER_
