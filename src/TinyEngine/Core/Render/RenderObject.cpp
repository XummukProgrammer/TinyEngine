#include "RenderObject.hpp"

namespace TinyEngine
{
	void RenderObject::Update(float deltaTime)
	{

	}

	void RenderObject::SetPosition(const PointF& position)
	{
	}

	PointF RenderObject::GetPosition() const
	{
		return {};
	}

	void RenderObject::SetScale(const PointF& factors)
	{
	}

	PointF RenderObject::GetScale() const
	{
		return {};
	}

	void RenderObject::SetRotation(float rotation)
	{
	}

	float RenderObject::GetRotation() const
	{
		return 1.f;
	}

	void RenderObject::SetTexture(std::string_view filePath)
	{
	}

	void RenderObject::SetTextureRect(const Rect& rectangle)
	{
	}

	bool RenderObject::IsPointIntersects(const PointF& point) const
	{
		return false;
	}

	bool RenderObject::IsRectIntersects(const RectF& rectangle) const
	{
		return false;
	}
}
