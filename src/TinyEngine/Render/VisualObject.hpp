#ifndef _VISUAL_OBJECT_HEADER_
#define _VISUAL_OBJECT_HEADER_

#include <TinyEngine/Render/IObject.hpp>

#include <SFML/Graphics.hpp>

#include <string>

namespace TinyEngine
{
	// Визуальный объект (Спрайт).
	class VisualObject final : public IObject
	{
	public:
		VisualObject() = default;
		~VisualObject() = default;

	public:
		// Окно рисуется.
		void OnWindowDrawed() override;

	public:
		// Установить текстуру из текстурных ассетов.
		void SetTexture(std::string_view assetId);
		const sf::Texture* GetTexture() const { return _sprite.getTexture(); }

		// Установить область текстуры.
		void SetTextureRect(const sf::IntRect& rect);
		const sf::IntRect& GetTextureRect() const { return _sprite.getTextureRect(); }

		void SetPosition(const sf::Vector2f& position) { _sprite.setPosition(position); }
		const sf::Vector2f& GetPosition() const { return _sprite.getPosition(); }

		void SetScale(const sf::Vector2f& factors) { _sprite.setScale(factors); }
		const sf::Vector2f& GetScale() const { return _sprite.getScale(); }

		void SetOrigin(const sf::Vector2f& origin) { _sprite.setOrigin(origin); }
		const sf::Vector2f& GetOrigin() const { _sprite.getOrigin(); }

		void SetRotation(float rotation) { _sprite.setRotation(rotation); }
		float GetRotation() const { return _sprite.getRotation(); }

		void SetColor(const sf::Color& color) { _sprite.setColor(color); }
		const sf::Color& GetColor() const { return _sprite.getColor(); }

		const sf::FloatRect& GetGlobalBounds() const { return _sprite.getGlobalBounds(); }

	private:
		// Спрайт.
		sf::Sprite _sprite;
	};
}

#endif // _VISUAL_OBJECT_HEADER_
