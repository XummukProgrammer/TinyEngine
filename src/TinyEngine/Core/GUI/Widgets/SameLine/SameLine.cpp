#include "SameLine.hpp"

#include <TinyEngine/Core/GUI/Widgets/SameLine/SameLineImGUIView.hpp>

namespace TinyEngine
{
    std::unique_ptr<IWidgetView> SameLine::MakeImGUIView() const
    {
        return std::make_unique<SameLineImGUIView>();
    }
}
