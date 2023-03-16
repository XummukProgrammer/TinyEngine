#ifndef _SAME_LINE_IMGUI_VIEW_HEADER_
#define _SAME_LINE_IMGUI_VIEW_HEADER_

#include <TinyEngine/Core/GUI/Widgets/SameLine/ISameLineView.hpp>

namespace TinyEngine
{
	class SameLineImGUIView final : public ISameLineView
	{
	public:
		SameLineImGUIView() = default;
		~SameLineImGUIView() = default;

	public:
		virtual void OnDraw() override;

		virtual void OnActive() override;
		virtual void OnDeactive() override;

		virtual void OnShow() override;
		virtual void OnHide() override;
	};
}

#endif // _SAME_LINE_IMGUI_VIEW_HEADER_
