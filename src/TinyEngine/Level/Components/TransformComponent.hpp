#ifndef _TRANSFORM_COMPONENT_HEADER_
#define _TRANSFORM_COMPONENT_HEADER_

#include <TinyEngine/Level/Component.hpp>

#include <SFML/System/Vector2.hpp>

namespace TinyEngine::Level
{
	class TransformComponent final : public Component
	{
	public:
		TransformComponent() = default;
		~TransformComponent() = default;

	public:
		void SetPosition(const sf::Vector2f& position);
		const sf::Vector2f& GetPosition() const;

		void SetScale(const sf::Vector2f& scale);
		const sf::Vector2f& GetScale() const;

		void SetRotation(float rotation);
		float GetRotation() const;

	private:
		sf::Vector2f _position;
		sf::Vector2f _scale = { 1.f, 1.f };
		float _rotation = 0.f;
	};
}

#endif // _TRANSFORM_COMPONENT_HEADER_
