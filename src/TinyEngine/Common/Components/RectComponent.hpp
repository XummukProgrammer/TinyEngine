#ifndef _RECT_COMPONENT_HEADER_
#define _RECT_COMPONENT_HEADER_

#include <TinyEngine/Level/Component.hpp>

#include <SFML/Graphics/Rect.hpp>

namespace TinyEngine::Common
{
	class RectComponent final : public Level::Component
	{
	public:
		RectComponent() = default;
		~RectComponent() = default;

	public:
		void SetRect(const sf::IntRect& rectangle);
		const sf::IntRect& GetRect() const;

	private:
		sf::IntRect _rectangle { 0, 0, 32, 32 };
	};
}

#endif // _RECT_COMPONENT_HEADER_
