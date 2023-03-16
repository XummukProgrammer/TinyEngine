#include "Widget.hpp"

namespace TinyEngine
{
    void Widget::OnDraw()
    {
        _view->OnDraw();
    }

    void Widget::MakeView(ViewType type)
    {
        switch (type)
        {
        case TinyEngine::Widget::ViewType::ImGUI:
            SetView(std::move(MakeImGUIView()));
            break;
        default:
            break;
        }

        _viewType = type;
    }

    void Widget::SetView(std::unique_ptr<IWidgetView>&& view)
    {
        _view = std::move(view);
    }

    void Widget::SetActive(bool isActive)
    {
        _isActive = isActive;

        if (_isActive)
        {
            OnActive();
            _view->OnActive();
        }
        else
        {
            OnDeactive();
            _view->OnDeactive();
        }
    }

    void Widget::SetVisible(bool isVisible)
    {
        _isVisible = isVisible;

        if (_isVisible)
        {
            OnShow();
            _view->OnShow();
        }
        else
        {
            OnHide();
            _view->OnHide();
        }
    }
}
