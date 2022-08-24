#ifndef _SFML_RENDER_UTILS_HEADER_
#define _SFML_RENDER_UTILS_HEADER_

#include <TinyEngine/Render/Point.hpp>
#include <TinyEngine/Render/Rect.hpp>

#include <SFML/Graphics.hpp>

namespace TinyEngine
{
	class SfmlRenderUtils
	{
	public:
		static sf::Vector2i PointToSfVector(const Point& point) { return { point.x, point.y }; }
		static sf::Vector2f PointToSfVector(const PointF& point) { return { point.x, point.y }; }
		static sf::IntRect RectToSfRect(const Rect& rectangle) { return { rectangle.x, rectangle.y, rectangle.w, rectangle.h }; }
		static sf::FloatRect RectToSfRect(const RectF& rectangle) { return { rectangle.x, rectangle.y, rectangle.w, rectangle.h }; }

		static Point SfVectorToPoint(const sf::Vector2i& vec) { return { vec.x, vec.y }; }
		static PointF SfVectorToPoint(const sf::Vector2f& vec) { return { vec.x, vec.y }; }
		static Rect SfRectToRect(const sf::IntRect& rectangle) { return { rectangle.left, rectangle.top, rectangle.width, rectangle.height }; }
		static RectF SfRectToRect(const sf::FloatRect& rectangle) { return { rectangle.left, rectangle.top, rectangle.width, rectangle.height }; }
	};
}

#endif // _SFML_RENDER_UTILS_HEADER_
