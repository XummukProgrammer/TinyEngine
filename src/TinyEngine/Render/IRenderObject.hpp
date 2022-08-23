#ifndef _INTERFACE_RENDER_OBJECT_HEADER_
#define _INTERFACE_RENDER_OBJECT_HEADER_

#include <TinyEngine/Render/Point.hpp>
#include <TinyEngine/Render/Rect.hpp>

#include <string>

namespace TinyEngine
{
	class IRenderObject
	{
	public:
		IRenderObject() = default;
		virtual ~IRenderObject() = default;

	public:
		virtual void SetPosition(const PointF& position) = 0;
		virtual PointF GetPosition() const = 0;

		virtual void SetScale(const PointF& factors) = 0;
		virtual PointF GetScale() const = 0;

		virtual void SetRotation(float rotation) = 0;
		virtual float GetRotation() const = 0;

		virtual void SetTexture(std::string_view assetId) = 0;
		virtual void SetTextureRect(const Rect& rectangle) = 0;

		virtual bool IsPointIntersects(const PointF& point) const = 0;
		virtual bool IsRectIntersects(const RectF& rectangle) const = 0;

	public:
		virtual void Update(float deltaTime) = 0;
	};
};

#endif // _INTERFACE_RENDER_OBJECT_HEADER_
