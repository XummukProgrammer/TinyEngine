#ifndef _GUI_INPUT_FLOAT_WIDGET_HEADER_
#define _GUI_INPUT_FLOAT_WIDGET_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Gui/GuiWidget.hpp>

#include <string>
#include <functional>

namespace TinyEngine
{
	class GuiInputFloatWidget final : public GuiWidget
	{
	public:
		using OnInputed = std::function<void(float)>;

	public:
		GuiInputFloatWidget() = default;
		~GuiInputFloatWidget() = default;

	public:
		static GuiInputFloatWidgetSharedPtr Create(std::string_view title, float value, const OnInputed& callback);

	public:
		void SetTitle(std::string_view title) { _title = title; }
		const std::string& GetTitle() const { return _title; }

		void SetValue(float value) { _value = value; }
		float GetValue() const { return _value; }
		
		void SetOnInputedCallback(const OnInputed& callback) { _onInputedCallback = callback; }

	public:
		void Draw(float deltaTime, IRenderWindowSharedPtr renderWindowPtr) override;

	private:
		std::string _title;
		float _value = 0.f;
		OnInputed _onInputedCallback;
	};
}

#endif // _GUI_INPUT_FLOAT_WIDGET_HEADER_
