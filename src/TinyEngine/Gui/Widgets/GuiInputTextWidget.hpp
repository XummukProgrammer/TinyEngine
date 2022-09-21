#ifndef _GUI_INPUT_TEXT_WIDGET_HEADER_
#define _GUI_INPUT_TEXT_WIDGET_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Gui/GuiWidget.hpp>

#include <string>
#include <functional>

namespace TinyEngine
{
	class GuiInputTextWidget final : public GuiWidget
	{
	public:
		using OnInputed = std::function<void(std::string_view)>;

	public:
		GuiInputTextWidget() = default;
		~GuiInputTextWidget() = default;

	public:
		static GuiInputTextWidgetSharedPtr Create(std::string_view title, std::string_view text, const OnInputed& callback);

	public:
		void SetTitle(std::string_view title) { _title = title; }
		const std::string& GetTitle() const { return _title; }
		
		void SetText(std::string_view text);
		std::string GetText() const;

		void SetOnInputedCallback(const OnInputed& callback) { _onInputedCallback = callback; }

	public:
		void Draw(float deltaTime) override;

	private:
		std::string _title;
		char _buffer[256];
		OnInputed _onInputedCallback;
	};
}

#endif // _GUI_INPUT_TEXT_WIDGET_HEADER_
