#ifndef _TEXT_BOX_HEADER_
#define _TEXT_BOX_HEADER_

#include <TinyEngine/Core/GUI/Widget.hpp>
#include <TinyEngine/Core/GUI/Widgets/TextBox/ITextBoxView.hpp>

namespace TinyEngine
{
	class TextBox final : public Widget
	{
	public:
		TextBox() = default;
		~TextBox() = default;

	public:
		void SetText(std::string_view text);
		void SetColor(const raylib::Color& color);
		void SetIsMarker(bool isMarker);

	private:
		virtual std::unique_ptr<IWidgetView> MakeImGUIView() const override;
	};
}

#endif // _TEXT_BOX_HEADER_
