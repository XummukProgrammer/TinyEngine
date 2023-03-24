#include "Child.hpp"

#include <TinyEngine/Core/GUI/Widgets/Child/ChildImGUIView.hpp>

namespace TinyEngine
{
    void Child::OnDraw()
    {
        Window::OnDraw();
    }

    std::unique_ptr<IWidgetView> Child::MakeImGUIView() const
    {
        return std::make_unique<ChildImGUIView>();
    }
}
