﻿#include "GuiPropertiesWidget.hpp"

#include <TinyEngine/Data/Meta/Class/MetaClass.hpp>

namespace TinyEngine
{
    GuiPropertiesWidgetSharedPtr GuiPropertiesWidget::Create()
    {
        auto widget = std::make_shared<GuiPropertiesWidget>();
        widget->SetName("Properties");
        return widget;
    }

    void GuiPropertiesWidget::InitFromMetaClass(MetaClassPtr metaClass)
    {
        metaClass->AddGuiWidgetsToContainer(this);
    }

    void GuiPropertiesWidget::Reset()
    {
        // TODO: Реализовать
    }
}