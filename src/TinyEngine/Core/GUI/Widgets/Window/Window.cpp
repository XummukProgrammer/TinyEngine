#include "Window.hpp"

#include <TinyEngine/Core/GUI/Widgets/Window/WindowImGUIView.hpp>

namespace TinyEngine
{
    void Window::OnInit()
    {
    }

    void Window::OnDeinit()
    {
    }

    void Window::OnActive()
    {
    }

    void Window::OnDeactive()
    {
    }

    void Window::OnShow()
    {
    }

    void Window::OnHide()
    {
    }

    void Window::OnDraw()
    {
        auto view = dynamic_cast<WindowImGUIView*>(GetView());
        view->Begin();
        _widgetsContainer.Draw();
        view->End();
    }

    void Window::SetTitle(std::string_view title)
    {
        dynamic_cast<WindowImGUIView*>(GetView())->SetTitle(title);
    }

    std::unique_ptr<IWidgetView> Window::MakeImGUIView() const
    {
        return std::make_unique<WindowImGUIView>();
    }
}
