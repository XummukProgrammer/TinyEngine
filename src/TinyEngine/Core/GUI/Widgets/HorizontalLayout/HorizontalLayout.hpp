#ifndef _HORIZONTAL_LAYOUT_HEADER_
#define _HORIZONTAL_LAYOUT_HEADER_

#include <TinyEngine/Core/GUI/Widgets/Window/Window.hpp>

namespace TinyEngine
{
	class HorizontalLayout final : public Window
	{
	public:
		HorizontalLayout() = default;
		~HorizontalLayout() = default;

	public:
		virtual void OnDraw() override;

	protected:
		virtual std::unique_ptr<IWidgetView> MakeImGUIView() const override;
	};
}

#endif // _HORIZONTAL_LAYOUT_HEADER_
