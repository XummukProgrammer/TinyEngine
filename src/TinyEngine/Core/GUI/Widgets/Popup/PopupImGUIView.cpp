#include "PopupImGUIView.hpp"

#include <TinyEngine/Core/GUI/Widget.hpp>

#include "imgui.h"

namespace TinyEngine
{
    bool PopupImGUIView::TryBegin()
    {
        return ImGui::BeginPopupModal(GetWidget()->GetName().c_str(), nullptr);
    }

    void PopupImGUIView::End()
    {
        ImGui::EndPopup();
    }
}
