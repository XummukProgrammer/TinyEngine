#include "ChildImGUIView.hpp"

#include <TinyEngine/Core/GUI/Widget.hpp>

#include "imgui.h"

namespace TinyEngine
{
    void ChildImGUIView::SetSize(const raylib::Vector2& size)
    {
        _size = size;
    }

    bool ChildImGUIView::TryBegin()
    {
        return ImGui::BeginChild(GetWidget()->GetName().c_str(), ImVec2(_size.x, _size.y), {}, _isHorizontalScrollbar ? ImGuiWindowFlags_HorizontalScrollbar : 0);
    }

    void ChildImGUIView::End()
    {
        ImGui::EndChild();
    }
}
