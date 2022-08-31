#include "GuiInputNumberWidget.hpp"

namespace TinyEngine
{
	GuiInputNumberWidgetSharedPtr GuiInputNumberWidget::Create(std::string_view title, int value, const OnInputed& callback)
	{
		auto widget = std::make_shared<GuiInputNumberWidget>();
		widget->SetTitle(title);
		widget->SetValue(value);
		widget->SetOnInputedCallback(callback);
		return widget;
	}

	void GuiInputNumberWidget::Draw(float deltaTime, IRenderWindowSharedPtr renderWindowPtr)
	{
		ImGui::PushID(_title.c_str());
		if (ImGui::InputInt(_title.c_str(), &_value) && _onInputedCallback)
		{
			_onInputedCallback(_value);
		}
		ImGui::PopID();
	}
}
