#include "Window.hpp"

#include <TinyEngine/Core/GUI/Widgets/Window/WindowImGUIView.hpp>

namespace TinyEngine
{
    void Window::Init()
    {
    }

    void Window::Deinit()
    {
    }

    void Window::Draw()
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
