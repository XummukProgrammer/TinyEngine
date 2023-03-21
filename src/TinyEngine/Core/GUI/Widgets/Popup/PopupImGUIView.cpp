#include "PopupImGUIView.hpp"

#include "imgui.h"

namespace TinyEngine
{
    void PopupImGUIView::SetTitle(std::string_view title)
    {
        _title = title;
    }

    bool PopupImGUIView::TryBegin()
    {
        return ImGui::BeginPopupModal(_title.c_str(), nullptr);
    }

    void PopupImGUIView::End()
    {
        ImGui::EndPopup();
    }
}
