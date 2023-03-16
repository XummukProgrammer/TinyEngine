#include "WindowImGUIView.hpp"

#include "imgui.h"

namespace TinyEngine
{
    void WindowImGUIView::Begin()
    {
        ImGui::Begin(_title.c_str());
    }

    void WindowImGUIView::End()
    {
        ImGui::End();
    }

    void WindowImGUIView::OnActive()
    {
    }

    void WindowImGUIView::OnDeactive()
    {
    }

    void WindowImGUIView::OnShow()
    {
    }

    void WindowImGUIView::OnHide()
    {
    }

    void WindowImGUIView::SetTitle(std::string_view title)
    {
        _title = title;
    }
}
