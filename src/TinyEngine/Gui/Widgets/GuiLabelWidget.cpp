#include "GuiLabelWidget.hpp"

namespace TinyEngine
{
	GuiLabelWidget::Ptr GuiLabelWidget::Create(std::string_view text)
	{
		auto widget = std::make_shared<GuiLabelWidget>();
		widget->SetText(text);
		return widget;
	}

	GuiLabelWidget::Ptr GuiLabelWidget::Create(std::string_view text,const ImVec4& color)
	{
		auto widget = Create(text);
		widget->SetColor(color);
		return widget;
	}

	GuiLabelWidget::Ptr GuiLabelWidget::Create(std::string_view text,bool isDisabled)
	{
		auto widget = Create(text);
		widget->SetDisabled(isDisabled);
		return widget;
	}

	void GuiLabelWidget::Draw(float deltaTime, IRenderWindowPtr renderWindowPtr)
	{
		if (_isDisabled)
		{
			ImGui::TextDisabled(_text.c_str());
		}
		else if (_color)
		{
			ImGui::TextColored(_color.value(), _text.c_str());
		}
		else
		{
			ImGui::Text(_text.c_str());
		}
	}
}
