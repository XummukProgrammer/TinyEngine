#include "HorizontalLayout.hpp"

#include <TinyEngine/Core/GUI/Widgets/SameLine/SameLineImGUIView.hpp>

namespace TinyEngine
{
    void HorizontalLayout::OnDraw()
    {
        GetRefWidgetsLayersContainer().Draw([this](Widget* widget, bool isLastElement)
            {
                if (!isLastElement)
                {
                    GetView()->OnDraw();
                }
            });
    }

    std::unique_ptr<IWidgetView> HorizontalLayout::MakeImGUIView() const
    {
        return std::make_unique<SameLineImGUIView>();
    }
}
