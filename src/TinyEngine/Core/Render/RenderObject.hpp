#ifndef _RENDER_OBJECT_HEADER_
#define _RENDER_OBJECT_HEADER_

#include <TinyEngine/Core/Render/Point.hpp>
#include <TinyEngine/Core/Render/Rect.hpp>

#include <SFML/Graphics.hpp>

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

		void SetTexture(std::string_view assetId);
		void SetTextureRect(const Rect& rectangle);

		bool IsPointIntersects(const PointF& point) const;
		bool IsRectIntersects(const RectF& rectangle) const;

		void SetLayerId(int layerId) { _layerId = layerId; }
		int GetLayerId() const { return _layerId; }

		void Update(float deltaTime);

		sf::Sprite& GetSprite() { return _sprite; }
		const sf::Sprite& GetConstSprite() const { return _sprite; }

	private:
		sf::Sprite _sprite;

		int _layerId = 0;
	};
};

#endif // _RENDER_OBJECT_HEADER_
