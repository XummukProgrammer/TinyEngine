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

    void WindowImGUIView::SetTitle(std::string_view title)
    {
        _title = title;
    }
}
