#include "Popup.hpp"

#include <TinyEngine/Core/GUI/Widgets/Popup/PopupImGUIView.hpp>

#include <TinyEngine/Core/Application/Application.hpp>
#include <TinyEngine/Core/GUI/GUI.hpp>

namespace TinyEngine
{
    void Popup::Open()
    {
        Application::GetSingleton().GetRefContext().GetGUI()->SetImGUIOpenPopup(GetName());
    }

    std::unique_ptr<IWidgetView> Popup::MakeImGUIView() const
    {
        return std::make_unique<PopupImGUIView>();
    }
}
