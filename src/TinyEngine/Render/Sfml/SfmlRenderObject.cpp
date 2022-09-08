#include "SfmlRenderObject.hpp"

#include <TinyEngine/Render/Sfml/SfmlRenderUtils.hpp>
#include <TinyEngine/Core/Assets/Assets.hpp>
#include <TinyEngine/Core/Assets/AssetTexture.hpp>

namespace TinyEngine
{
	void SfmlRenderObject::Update(float deltaTime)
	{
	}

	void SfmlRenderObject::SetPosition(const PointF& position)
	{
		_sprite.setPosition(SfmlRenderUtils::PointToSfVector(position));
	}

	PointF SfmlRenderObject::GetPosition() const
	{
		return SfmlRenderUtils::SfVectorToPoint(_sprite.getPosition());
	}

	void SfmlRenderObject::SetScale(const PointF& factors)
	{
		_sprite.setScale(SfmlRenderUtils::PointToSfVector(factors));
	}

	PointF SfmlRenderObject::GetScale() const
	{
		return SfmlRenderUtils::SfVectorToPoint(_sprite.getScale());
	}

	void SfmlRenderObject::SetRotation(float rotation)
	{
		_sprite.setRotation(rotation);
	}

	float SfmlRenderObject::GetRotation() const
	{
		return _sprite.getRotation();
	}

	void SfmlRenderObject::SetTexture(std::string_view filePath)
	{
		AssetSfmlTexture a;
		// TODO: Заглушка, реализовать потом правильно!
		auto texture = Assets::GetInstance()->GetAssetHolder().GetAsset<AssetSfmlTexture>("");
		if (texture)
		{
			_sprite.setTexture(texture->GetTexture());
		}
		else
		{
			_sprite.setTexture(sf::Texture());
		}
	}

	void SfmlRenderObject::SetTextureRect(const Rect& rectangle)
	{
		_sprite.setTextureRect(SfmlRenderUtils::RectToSfRect(rectangle));
	}

	bool SfmlRenderObject::IsPointIntersects(const PointF& point) const
	{
		return _sprite.getGlobalBounds().contains(SfmlRenderUtils::PointToSfVector(point));
	}

	bool SfmlRenderObject::IsRectIntersects(const RectF& rectangle) const
	{
		return _sprite.getGlobalBounds().intersects(SfmlRenderUtils::RectToSfRect(rectangle));
	}
}
