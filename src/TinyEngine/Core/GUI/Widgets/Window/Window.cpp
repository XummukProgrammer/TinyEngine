#include "Window.hpp"

#include <TinyEngine/Core/GUI/Widgets/Window/WindowImGUIView.hpp>

namespace TinyEngine
{
    void Window::OnInit()
    {
        Widget::OnInit();

        _widgetsLayersContainer.Init();
    }

    void Window::OnDeinit()
    {
        Widget::OnDeinit();

        _widgetsLayersContainer.Deinit();
    }

    void Window::OnDraw()
    {
        auto view = dynamic_cast<IWindowView*>(GetView());
        if (view->TryBegin())
        {
            _widgetsLayersContainer.Draw();
        }
        view->End();
    }

    std::unique_ptr<IWidgetView> Window::MakeImGUIView() const
    {
        return std::make_unique<WindowImGUIView>();
    }

    std::unique_ptr<IWidgetView> MainImGUIWindow::MakeImGUIView() const
    {
        return std::make_unique<MainWindowImGUIView>();
    }
}
