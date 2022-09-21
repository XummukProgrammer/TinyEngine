#ifndef _GUI_BUTTON_WIDGET_HEADER_
#define _GUI_BUTTON_WIDGET_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Gui/GuiWidget.hpp>

#include <string>
#include <functional>

namespace TinyEngine
{
	class GuiButtonWidget final : public GuiWidget
	{
	public:
		using OnClicked = std::function<void()>;

	public:
		GuiButtonWidget() = default;
		~GuiButtonWidget() = default;

	public:
		static GuiButtonWidgetSharedPtr Create(std::string_view text, const OnClicked& callback);

	public:
		void SetText(std::string_view text) { _text = text; }
		const std::string& GetText() const { return _text; }

		void SetOnClickedCallback(OnClicked callback) { _onClickedCallback = callback; }

	public:
		void Draw(float deltaTime) override;

	private:
		std::string _text;
		OnClicked _onClickedCallback;
	};
}

#endif // _GUI_BUTTON_WIDGET_HEADER_
