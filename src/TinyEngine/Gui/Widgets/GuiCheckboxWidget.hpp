#ifndef _CHECKBOX_WIDGET_HEADER_
#define _CHECKBOX_WIDGET_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Gui/GuiWidget.hpp>

#include <string>
#include <functional>

namespace TinyEngine
{
	class GuiCheckboxWidget final : public GuiWidget
	{
	public:
		using OnChanged = std::function<void(bool)>;

	public:
		GuiCheckboxWidget() = default;
		~GuiCheckboxWidget() = default;

	public:
		static GuiCheckboxWidgetSharedPtr Create(std::string_view title, bool value, const OnChanged& callback);

	public:
		void SetTitle(std::string_view title) { _title = title; }
		const std::string& GetTitle() const { return _title; }

		void SetValue(bool value) { _value = value; }
		bool GetValue() const { return _value; }

		void SetOnChangedCallback(const OnChanged& callback) { _onChangedCallback = callback; }

	public:
		void Draw(float deltaTime) override;

	private:
		std::string _title;
		bool _value = false;
		OnChanged _onChangedCallback;
	};
}

#endif // _CHECKBOX_WIDGET_HEADER_
