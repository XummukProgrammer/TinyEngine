#ifndef _SFML_RENDER_OBJECT_HEADER_
#define _SFML_RENDER_OBJECT_HEADER_

#include <TinyEngine/Render/IRenderObject.hpp>

#include <SFML/Graphics.hpp>

namespace TinyEngine
{
	class SfmlRenderObject final : public IRenderObject
	{
	public:
		SfmlRenderObject() = default;
		~SfmlRenderObject() = default;

	public:
		void Update(float deltaTime) override;

		void SetPosition(const PointF& position) override;
		PointF GetPosition() const override;

		void SetScale(const PointF& factors) override;
		PointF GetScale() const override;

		void SetRotation(float rotation) override;
		float GetRotation() const override;

		void SetTexture(std::string_view assetId) override;
		void SetTextureRect(const Rect& rectangle) override;

		bool IsPointIntersects(const PointF& point) const override;
		bool IsRectIntersects(const RectF& rectangle) const override;

	public:
		sf::Sprite& GetSprite() { return _sprite; }
		const sf::Sprite& GetConstSprite() const { return _sprite; }

	private:
		sf::Sprite _sprite;
	};
}

#endif // _SFML_RENDER_OBJECT_HEADER_
