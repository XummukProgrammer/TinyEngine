#ifndef _CHILD_IMGUI_VIEW_HEADER_
#define _CHILD_IMGUI_VIEW_HEADER_

#include <TinyEngine/Core/GUI/Widgets/Child/IChildView.hpp>

#include "raylib-cpp.hpp"

namespace TinyEngine
{
	class ChildImGUIView final : public IChildView
	{
	public:
		ChildImGUIView() = default;
		~ChildImGUIView() = default;

	public:
		virtual void SetTitle(std::string_view title) override;
		void SetSize(const raylib::Vector2& size);
		void SetIsHorizontalScrollbar(bool isEnable) { _isHorizontalScrollbar = isEnable; }

		virtual bool TryBegin() override;
		virtual void End() override;

		virtual void OnDraw() override {}

	private:
		std::string _title;
		raylib::Vector2 _size{ 0, 0 };
		bool _isHorizontalScrollbar = false;
	};
}

#endif // _CHILD_IMGUI_VIEW_HEADER_
