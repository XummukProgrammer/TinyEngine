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
    void ButtonImGUIView::OnActive()
    {
    }
    void ButtonImGUIView::OnDeactive()
    {
    }
    void ButtonImGUIView::OnShow()
    {
    }
    void ButtonImGUIView::OnHide()
    {
    }
}
