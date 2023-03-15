#include "SameLineImGUIView.hpp"

#include "imgui.h"

namespace TinyEngine
{
    void SameLineImGUIView::OnDraw()
    {
        ImGui::SameLine();
    }
}
