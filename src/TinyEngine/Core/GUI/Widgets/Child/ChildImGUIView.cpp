#include "ChildImGUIView.hpp"

#include "imgui.h"

namespace TinyEngine
{
    void ChildImGUIView::SetTitle(std::string_view title)
    {
        _title = title;
    }

    bool ChildImGUIView::TryBegin()
    {
        return ImGui::BeginChild(_title.c_str(), {}, {}, ImGuiWindowFlags_HorizontalScrollbar);
    }

    void ChildImGUIView::End()
    {
        ImGui::EndChild();
    }
}
