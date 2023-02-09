#ifndef _ANCHOR_HEADER_
#define _ANCHOR_HEADER_

#include <TinyEngine/Core/VisualObject/Alignment.hpp>
#include <raylib-cpp.hpp>

namespace TinyEngine
{
	class Anchor
	{
	public:
		void SetHorizontalAlignment(HorizontalAlignment horizontalAlignment) { _horizontalAlignment = horizontalAlignment; }
		HorizontalAlignment GetHorizontalAlignment() const { return _horizontalAlignment; }

		void SetVerticalALignment(VerticalAlignment verticalAlignment) { _verticalAlignment = verticalAlignment; }
		VerticalAlignment GetVerticalAlignment() const { return _verticalAlignment; }

		RRectangle GetRectangle(const RVector2& position, const RVector2& localScale) const;

	private:
		HorizontalAlignment _horizontalAlignment = HorizontalAlignment::Center;
		VerticalAlignment _verticalAlignment = VerticalAlignment::Center;
	};
}

#endif // _ANCHOR_HEADER_
