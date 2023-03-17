#ifndef _I_BUTTON_VIEW_HEADER_
#define _I_BUTTON_VIEW_HEADER_

#include <TinyEngine/Core/GUI/WidgetView.hpp>

#include <string>

namespace TinyEngine
{
	class IButtonView : public IWidgetView
	{
	public:
		IButtonView() = default;
		~IButtonView() = default;

	public:
		void SetText(std::string_view text) { _text = text; }

	protected:
		void OnPressed();

	protected:
		const std::string& GetText() const { return _text; }

	private:
		std::string _text;
	};
}

#endif // _I_BUTTON_VIEW_HEADER_
