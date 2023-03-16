#include "SameLine.hpp"

#include <TinyEngine/Core/GUI/Widgets/SameLine/SameLineImGUIView.hpp>

namespace TinyEngine
{
    void SameLine::OnActive()
    {
    }
    void SameLine::OnDeactive()
    {
    }
    void SameLine::OnShow()
    {
    }
    void SameLine::OnHide()
    {
    }
    std::unique_ptr<IWidgetView> SameLine::MakeImGUIView() const
    {
        return std::make_unique<SameLineImGUIView>();
    }
}
