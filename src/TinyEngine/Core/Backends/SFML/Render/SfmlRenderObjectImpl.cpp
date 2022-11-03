#include <TinyEngine/Core/Render/RenderObject.hpp>

#include <SFML/Graphics.hpp>

namespace TinyEngine
{
	void RenderObject::Update(float deltaTime)
	{

	}

	void RenderObject::SetPosition(const PointF& position)
	{
		_sprite.setPosition({ position.GetX(), position.GetY() });
	}

	PointF RenderObject::GetPosition() const
	{
		const auto& position = _sprite.getPosition();
		return { position.x, position.y };
	}

	void RenderObject::SetScale(const PointF& factors)
	{
		_sprite.setScale({ factors.GetX(), factors.GetY() });
	}

	PointF RenderObject::GetScale() const
	{
		const auto& scale = _sprite.getScale();
		return { scale.x, scale.y };
	}

	void RenderObject::SetRotation(float rotation)
	{
		_sprite.setRotation(rotation);
	}

	float RenderObject::GetRotation() const
	{
		return _sprite.getRotation();
	}

	void RenderObject::SetTexture(std::string_view filePath)
	{
		// TODO: Доработать
		_sprite.setTexture(sf::Texture());
		_sprite.setColor(sf::Color::White);
	}

	void RenderObject::SetTextureRect(const Rect& rectangle)
	{
		_sprite.setTextureRect({ rectangle.x, rectangle.y, rectangle.w, rectangle.h });
	}

	bool RenderObject::IsPointIntersects(const PointF& point) const
	{
		return _sprite.getGlobalBounds().contains({ point.GetX(), point.GetY() });
	}

	bool RenderObject::IsRectIntersects(const RectF& rectangle) const
	{
		return _sprite.getGlobalBounds().intersects({ rectangle.x, rectangle.y, rectangle.w, rectangle.h });
	}
}
