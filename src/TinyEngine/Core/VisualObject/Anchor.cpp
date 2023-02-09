#include "Anchor.hpp"

#include <TinyEngine/Core/Application/Application.hpp>

namespace TinyEngine
{
    RVector2 TinyEngine::Anchor::GetPositionWithAnchor(const RVector2& centerPosition, const RVector2& localScale) const
    {
        RVector2 position = centerPosition;
        
        const float scalePixelCoef = Application::GetSingleton().GetContext().GetScalePixelCoef();

        const float scaleHalfWidth = localScale.x * scalePixelCoef / 2.f;
        const float scaleHalfHeight = localScale.y * scalePixelCoef / 2.f;

        switch (_horizontalAlignment)
        {
        case TinyEngine::HorizontalAlignment::Center:
            break;
        case TinyEngine::HorizontalAlignment::Left:
            position.x -= scaleHalfWidth;
            break;
        case TinyEngine::HorizontalAlignment::Right:
            position.x += scaleHalfWidth;
            break;
        default:
            break;
        };

        switch (_verticalAlignment)
        {
        case TinyEngine::VerticalAlignment::Center:
            break;
        case TinyEngine::VerticalAlignment::Top:
            position.y -= scaleHalfHeight;
            break;
        case TinyEngine::VerticalAlignment::Botton:
            position.y += scaleHalfHeight;
            break;
        default:
            break;
        }

        return position;
    }
}
