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

	protected:
		virtual std::unique_ptr<IWidgetView> MakeImGUIView() const override;
	};

	class ImGUIChild : public Child
	{
	public:
		ImGUIChild() = default;
		virtual ~ImGUIChild() = default;

	protected:
		virtual ViewType GetViewType() const override { return ViewType::ImGUI; }
	};
}

#endif // _CHILD_HEADER_
