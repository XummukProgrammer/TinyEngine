#include "VisualObject.hpp"

#include <TinyEngine/Core/Core.hpp>

namespace TinyEngine
{
	void VisualObject::OnWindowUpdated()
	{ 
		_sprite.setTexture(sf::Texture());
		_sprite.setTextureRect({ 0, 0, 32, 32 });
	}

	void VisualObject::OnWindowDrawed()
	{ 
		Core::GetApplication().GetWindow().DrawObject(_sprite);
	}
}
