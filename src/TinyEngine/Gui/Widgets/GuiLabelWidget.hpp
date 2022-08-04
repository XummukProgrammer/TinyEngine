#ifndef _GUI_LABEL_WIDGET_HEADER_
#define _GUI_LABEL_WIDGET_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Gui/GuiWidget.hpp>

#include <string>
#include <optional>
#include <memory>

namespace TinyEngine
{
	class GuiLabelWidget final : public GuiWidget
	{
	public:
		GuiLabelWidget() = default;
		~GuiLabelWidget() = default;

	public:
		static GuiLabelWidgetSharedPtr Create(std::string_view text);
		static GuiLabelWidgetSharedPtr Create(std::string_view text, const ImVec4& color);
		static GuiLabelWidgetSharedPtr Create(std::string_view text, bool isDisabled);

	public:
		void Draw(float deltaTime, IRenderWindowSharedPtr renderWindowPtr) override;

	public:
		// Взаимозаменяем с SetColor.
		void SetDisabled(bool isDisabled) { _isDisabled = isDisabled; }
		bool IsDisabled() const { return _isDisabled; }

		void SetText(std::string_view text) { _text = text; }
		const std::string& GetText() const { return _text; }

		void SetColor(const ImVec4& color) { _color = color; }
		std::optional<ImVec4> GetColor() const { return _color; }

	private:
		bool _isDisabled = false;
		std::string _text;
		std::optional<ImVec4> _color;
	};
}

#endif // _GUI_LABEL_WIDGET_HEADER_
