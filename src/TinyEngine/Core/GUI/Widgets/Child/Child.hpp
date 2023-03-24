#ifndef _CHILD_HEADER_
#define _CHILD_HEADER_

#include <TinyEngine/Core/GUI/Widgets/Window/Window.hpp>

namespace TinyEngine
{
	class Child : public Window
	{
	public:
		Child() = default;
		~Child() = default;

	public:
		virtual void OnDraw() override;

	protected:
		virtual std::unique_ptr<IWidgetView> MakeImGUIView() const override;
	};
}

#endif // _CHILD_HEADER_
