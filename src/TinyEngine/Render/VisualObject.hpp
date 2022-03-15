#ifndef _VISUAL_OBJECT_HEADER_
#define _VISUAL_OBJECT_HEADER_

#include <TinyEngine/Render/IObject.hpp>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <memory>

namespace sf
{
	class Sprite;
}

namespace TinyEngine::Render
{
	class VisualObject final : public IObject
	{
	public:
		using SpritePtr = std::shared_ptr<sf::Sprite>;

	public:
		VisualObject();
		~VisualObject() = default;

	public:
		void OnDeinit() override;

		void OnDraw() override;

	public:
		SpritePtr GetSprite() const;

		void SetPosition(const sf::Vector2f& position);
		const sf::Vector2f& GetPosition() const;

		void SetScale(const sf::Vector2f& scale);
		const sf::Vector2f& GetScale() const;

		void SetRotation(float rotation);
		float GetRotation() const;

		void SetRect(const sf::IntRect& rectangle);
		const sf::IntRect& GetRect() const;

		void SetTexture(const sf::Texture& texture);

	private:
		SpritePtr _sprite;
	};
}

#endif // _VISUAL_OBJECT_HEADER_
