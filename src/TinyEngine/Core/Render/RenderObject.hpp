#ifndef _RENDER_OBJECT_HEADER_
#define _RENDER_OBJECT_HEADER_

#include <TinyEngine/Core/Render/Point.hpp>
#include <TinyEngine/Core/Render/Rect.hpp>

#include "raylib.h"

#include <string>

namespace TinyEngine
{
	class RenderObject final
	{
	public:
		RenderObject() = default;
		~RenderObject() = default;

	public:
		void SetPosition(const PointF& position);
		PointF GetPosition() const;

		void SetScale(const PointF& factors);
		PointF GetScale() const;

		void SetRotation(float rotation);
		float GetRotation() const;

		void SetTexture(std::string_view resourceId);
		void SetTextureRect(const Rect& rectangle);

		void SetLayerId(int layerId) { _layerId = layerId; }
		int GetLayerId() const { return _layerId; }

		void SetOrigin(const PointF& origin);
		PointF GetOrigin() const;

		void Update(float deltaTime);
		void Draw();

	private:
		int _layerId = 0;
		TextureResourceWeakPtr _textureResourceWeak;
		Vector2 _position { 0.f, 0.f };
		Vector2 _scale { 1.f, 1.f };
		float _rotation = 0.f;
		Rectangle _rectangle;
		Vector2 _origin { 0.f, 0.f };
	};
};

#endif // _RENDER_OBJECT_HEADER_
