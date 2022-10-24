#ifndef _TRANSFORM_COMPONENT_HEADER_
#define _TRANSFORM_COMPONENT_HEADER_

#include <TinyEngine/World/Component.hpp>
#include <TinyEngine/Render/Point.hpp>

namespace TinyEngine
{
	class TransformComponent final : public Component
	{
		TINY_ENGINE_META_CLASS_DERIVED_BEGIN(TransformComponent, Component)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_position, "Position", "Position");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_scale, "Scale", "Scale");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_rotation, "Rotation", "Rotation");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		TransformComponent() = default;
		~TransformComponent() = default;

	public:
		void SetPosition(const PointF& point) { _position = point; }
		const PointF& GetPosition() const { return _position; }

		void SetScale(const PointF& point) { _scale = point; }
		const PointF& GetScale() const { return _scale; }

		void SetRotation(float rotation) { _rotation = rotation; }
		float GetRotation() const { return _rotation; }

	private:
		PointF _position = {};
		PointF _scale = { 1.f, 1.f };
		float _rotation = 0.f;
	};
}

#endif // _TRANSFORM_COMPONENT_HEADER_
