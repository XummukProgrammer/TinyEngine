#include "TransformComponent.hpp"

namespace TinyEngine::Level
{
	void TransformComponent::SetPosition(const sf::Vector2f& position)
	{ 
		_position = position;
	}

	const sf::Vector2f& TransformComponent::GetPosition() const
	{
		return _position;
	}

	void TransformComponent::SetScale(const sf::Vector2f& scale)
	{ 
		_scale = scale;
	}

	const sf::Vector2f& TransformComponent::GetScale() const
	{
		return _scale;
	}

	void TransformComponent::SetRotation(float rotation)
	{ 
		_rotation = rotation;
	}

	float TransformComponent::GetRotation() const
	{
		return _rotation;
	}
}
