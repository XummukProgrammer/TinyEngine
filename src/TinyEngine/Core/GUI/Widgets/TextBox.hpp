#ifndef _TEXT_BOX_HEADER_
#define _TEXT_BOX_HEADER_

#include <TinyEngine/Core/GUI/Widget.hpp>
#include <TinyEngine/Core/GUI/Widgets/ITextBoxView.hpp>

namespace TinyEngine
{
	class TextBox final : public Widget
	{
	public:
		TextBox() = default;
		~TextBox() = default;

	public:
		virtual void Init() override;
		virtual void Deinit() override;

	public:
		void SetText(std::string_view text);

	private:
		std::unique_ptr<ITextBoxView> GetTextBoxView() const;
	};
}

#endif // _TEXT_BOX_HEADER_
