#ifndef _GUI_INPUT_TEXT_WIDGET_HEADER_
#define _GUI_INPUT_TEXT_WIDGET_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Gui/GuiWidget.hpp>

#include <string>

namespace TinyEngine
{
	class GuiInputTextWidget final : public GuiWidget
	{
	public:
		GuiInputTextWidget() = default;
		~GuiInputTextWidget() = default;

	public:
		static GuiInputTextWidgetSharedPtr Create(std::string_view title);

	public:
		void SetTitle(std::string_view title) { _title = title; }
		const std::string& GetTitle() const { return _title; }

	public:
		void Draw(float deltaTime, IRenderWindowSharedPtr renderWindowPtr) override;

	private:
		std::string _title;
		char _buffer[256];
	};
}

#endif // _GUI_INPUT_TEXT_WIDGET_HEADER_
