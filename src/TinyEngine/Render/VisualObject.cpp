#include "VisualObject.hpp"

#include <TinyEngine/Core/Context.hpp>
#include <TinyEngine/Core/Window.hpp>

#include <SFML/Graphics.hpp>

namespace TinyEngine::Render
{
	VisualObject::VisualObject()
		: _sprite(std::make_shared<sf::Sprite>())
	{
	}

	void VisualObject::OnDeinit()
	{ 
		_sprite.reset();
	}

	void VisualObject::OnDraw()
	{ 
		sf::Texture texture;
		_sprite->setTexture(texture);
		_sprite->setTextureRect({ 0, 0, 100, 100 });
		Core::Window::GetInstance().Draw(*_sprite.get());
	}

	VisualObject::SpritePtr VisualObject::GetSprite() const
	{
		return _sprite;
	}

	void VisualObject::SetPosition(const sf::Vector2f& position)
	{ 
		_sprite->setPosition(position);
	}

	const sf::Vector2f& VisualObject::GetPosition() const
	{
		return _sprite->getPosition();
	}

	void VisualObject::SetScale(const sf::Vector2f& scale)
	{ 
		_sprite->setScale(scale);
	}

	const sf::Vector2f& VisualObject::GetScale() const
	{
		return _sprite->getScale();
	}

	void VisualObject::SetRotation(float rotation)
	{ 
		_sprite->setRotation(rotation);
	}

	float VisualObject::GetRotation() const
	{
		return _sprite->getRotation();
	}
}
