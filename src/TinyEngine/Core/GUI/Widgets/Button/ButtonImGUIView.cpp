#include "ButtonImGUIView.hpp"

#include "imgui.h"

namespace TinyEngine
{
    void ButtonImGUIView::OnDraw()
    {
        if (ImGui::Button(GetText().c_str()))
        {
            OnPressed();
        }
    }
}
