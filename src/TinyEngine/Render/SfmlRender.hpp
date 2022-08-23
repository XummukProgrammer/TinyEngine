#ifndef _SFML_RENDER_HEADER_
#define _SFML_RENDER_HEADER_

#include <TinyEngine/Render/Render.hpp>

#include <SFML/Graphics.hpp>

#include <memory>
#include <list>

namespace TinyEngine
{
	class SfmlRenderUtils
	{
	public:
		static sf::Vector2i PointToSfVector(const Point& point) { return { point.x, point.y }; }
		static sf::Vector2f PointToSfVector(const PointF& point) { return { point.x, point.y }; }
		static sf::IntRect RectToSfRect(const Rect& rectangle) { return { rectangle.x, rectangle.y, rectangle.w, rectangle.h }; }
		static sf::FloatRect RectToSfRect(const RectF& rectangle) { return { rectangle.x, rectangle.y, rectangle.w, rectangle.h }; }

		static Point SfVectorToPoint(const sf::Vector2i& vec) { return { vec.x, vec.y }; }
		static PointF SfVectorToPoint(const sf::Vector2f& vec) { return { vec.x, vec.y }; }
		static Rect SfRectToRect(const sf::IntRect& rectangle) { return { rectangle.left, rectangle.top, rectangle.width, rectangle.height }; }
		static RectF SfRectToRect(const sf::FloatRect& rectangle) { return { rectangle.left, rectangle.top, rectangle.width, rectangle.height }; }
	};

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

	class SfmlRenderWindow final : public IRenderWindow
	{
	public:
		using ObjectsList = std::list<SfmlRenderObjectPtr>;

	public:
		SfmlRenderWindow() = default;
		~SfmlRenderWindow() = default;

	public:
		void Create(const RenderWindowSettings& windowSettings) override;
		GuiDelegateUniquePtr CreateDelegate() const override;
		bool IsClosed() const override;
		void Clear() override;
		void ExtractEvents() override;
		void Draw(IRenderObject* object) const override;
		void Display() override;
		void Close() override;

		void ResetClock() override;
		void UpdateClock() override;
		float GetDeltaTime() const override { return _deltaTime.asSeconds(); }

	public:
		sf::RenderWindow* GetRenderWindow() const { return _windowPtr.get(); }
		const sf::Event& GetEvent() const { return _event; }

	private:
		std::unique_ptr<sf::RenderWindow> _windowPtr;
		sf::Event _event;
		sf::Clock _clock;
		sf::Time _deltaTime;
	};
}

#endif // _SFML_RENDER_HEADER_
