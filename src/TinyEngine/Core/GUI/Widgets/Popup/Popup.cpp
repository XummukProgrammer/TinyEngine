#include "Popup.hpp"

#include <TinyEngine/Core/GUI/Widgets/Popup/PopupImGUIView.hpp>

namespace TinyEngine
{
    std::unique_ptr<IWidgetView> Popup::MakeImGUIView() const
    {
        return std::make_unique<PopupImGUIView>();
    }
}
