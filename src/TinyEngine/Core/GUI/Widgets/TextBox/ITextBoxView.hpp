#ifndef _I_TEXT_BOX_VIEW_HEADER_
#define _I_TEXT_BOX_VIEW_HEADER_

#include <TinyEngine/Core/GUI/WidgetView.hpp>

#include "raylib-cpp.hpp"

#include <string>

namespace TinyEngine
{
	class ITextBoxView : public IWidgetView
	{
	public:
		ITextBoxView() = default;
		virtual ~ITextBoxView() = default;

	public:
		virtual void SetText(std::string_view text) = 0;
		virtual void SetColor(const raylib::Color& color) = 0;
		virtual void SetIsMarker(bool isMarker) = 0;
	};
}

#endif // _I_TEXT_BOX_VIEW_HEADER_
