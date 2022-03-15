#include "RectComponent.hpp"

namespace TinyEngine::Common
{
	void RectComponent::SetRect(const sf::IntRect& rectangle)
	{ 
		_rectangle = rectangle;
	}

	const sf::IntRect& RectComponent::GetRect() const
	{
		return _rectangle;
	}
}
