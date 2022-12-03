#include "RenderObject.hpp"

#include <TinyEngine/Core/Assets/Resources/Resources.hpp>
#include <TinyEngine/Core/Assets/Resources/Common/TextureResource.hpp>

namespace TinyEngine
{
	void RenderObject::SetOrigin(const PointF& origin)
	{
		_origin.x = origin.GetX();
		_origin.y = origin.GetY();
	}

	PointF RenderObject::GetOrigin() const
	{
		return { _origin.x, _origin.y };
	}

	void RenderObject::Update(float deltaTime)
	{

	}

	void RenderObject::Draw()
	{
		if (auto textureResource = _textureResourceWeak.lock())
		{
			auto& texture = textureResource->GetTexture();
			Rectangle dest = { _position.x, _position.y, _rectangle.width * _scale.x, _rectangle.height * _scale.y };
			DrawTexturePro(texture, _rectangle, dest, _origin, _rotation, WHITE);
		}
	}

	void RenderObject::SetPosition(const PointF& position)
	{
		_position.x = position.GetX();
		_position.y = position.GetY();
	}

	PointF RenderObject::GetPosition() const
	{
		return { _position.x, _position.y };
	}

	void RenderObject::SetScale(const PointF& factors)
	{
		_scale.x = factors.GetX();
		_scale.y = factors.GetY();
	}

	PointF RenderObject::GetScale() const
	{
		return { _scale.x, _scale.y };
	}

	void RenderObject::SetRotation(float rotation)
	{
		_rotation = rotation;
	}

	float RenderObject::GetRotation() const
	{
		return _rotation;
	}

	void RenderObject::SetTexture(std::string_view resourceId)
	{
		_textureResourceWeak = Resources::GetInstance()->GetResource<TextureResource>(resourceId);
	}

	void RenderObject::SetTextureRect(const Rect& rectangle)
	{
		_rectangle.x = static_cast<float>(rectangle.x);
		_rectangle.y = static_cast<float>(rectangle.y);
		_rectangle.width = static_cast<float>(rectangle.w);
		_rectangle.height = static_cast<float>(rectangle.h);
	}
}
