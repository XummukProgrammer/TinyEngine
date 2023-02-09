#include "Anchor.hpp"

#include <TinyEngine/Core/Application/Application.hpp>

namespace TinyEngine
{
	RRectangle Anchor::GetRectangle(const RVector2& position, const RVector2& localScale) const
	{
		const float scalePixelCoef = Application::GetSingleton().GetContext().GetScalePixelCoef();
		const float width = localScale.x * scalePixelCoef;
		const float height = localScale.y * scalePixelCoef;
		const float halfWidth = width / 2.f;
		const float halfHeight = height / 2.f;

		RVector2 rectanglePosition = position;

		switch (_horizontalAlignment)
		{
		case TinyEngine::HorizontalAlignment::Center:
			rectanglePosition.x -= halfWidth;
			break;
		case TinyEngine::HorizontalAlignment::Left:
			break;
		case TinyEngine::HorizontalAlignment::Right:
			rectanglePosition.x -= width;
			break;
		default:
			break;
		}
		
		switch (_verticalAlignment)
		{
		case TinyEngine::VerticalAlignment::Center:
			rectanglePosition.y -= halfHeight;
			break;
		case TinyEngine::VerticalAlignment::Top:
			break;
		case TinyEngine::VerticalAlignment::Bottom:
			rectanglePosition.y -= height;
			break;
		default:
			break;
		}

		RRectangle rectangle;
		rectangle.SetPosition(rectanglePosition);
		rectangle.SetSize({ width, height });

		return rectangle;
	}
}
