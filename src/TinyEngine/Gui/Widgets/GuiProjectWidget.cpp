#include "GuiProjectWidget.hpp"

#include <TinyEngine/Gui/Widgets/GuiLabelWidget.hpp>

namespace TinyEngine
{
    GuiProjectWidgetSharedPtr GuiProjectWidget::Create()
    {
        auto widget = std::make_shared<GuiProjectWidget>();
		widget->SetName("ProjectWindow");

        widget->AddWidget("PrintName", GuiLabelWidget::Create("Print Name:"));
        widget->AddWidget("PrintPath", GuiLabelWidget::Create("Print Path:"));

		return widget;
    }
}
