#include "VisualObject.hpp"

#include <TinyEngine/Core/Context.hpp>
#include <TinyEngine/Core/Window.hpp>

#include <SFML/Graphics.hpp>

namespace TinyEngine::Render
{
	void VisualObject::OnDraw()
	{ 
		sf::Sprite sprite;
		sf::Texture texture;
		sprite.setTexture(texture);
		sprite.setTextureRect({ 0, 0, 100, 100 });
		Core::Context::GetInstance().GetWindow()->Draw(sprite);
	}
}
