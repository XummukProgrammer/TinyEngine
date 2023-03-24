#include "ChildImGUIView.hpp"

#include "imgui.h"

namespace TinyEngine
{
    void ChildImGUIView::SetTitle(std::string_view title)
    {
        _title = title;
    }

    void ChildImGUIView::SetSize(const raylib::Vector2& size)
    {
        _size = size;
    }

    bool ChildImGUIView::TryBegin()
    {
        return ImGui::BeginChild(_title.c_str(), ImVec2(_size.x, _size.y), {}, _isHorizontalScrollbar ? ImGuiWindowFlags_HorizontalScrollbar : 0);
    }

    void ChildImGUIView::End()
    {
        ImGui::EndChild();
    }
}
