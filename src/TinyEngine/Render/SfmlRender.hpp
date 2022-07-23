#ifndef _SFML_RENDER_HEADER_
#define _SFML_RENDER_HEADER_

#include <TinyEngine/Render/Render.hpp>

#include <SFML/Graphics.hpp>

#include <memory>
#include <list>

namespace TinyEngine
{
	class SfmlRenderObject;

	using SfmlRenderObjectPtr = std::shared_ptr<SfmlRenderObject>;

	class SfmlRenderUtils
	{
	public:
		static sf::Vector2i PointToSfVector(const Point& point) { return { point.x, point.y }; }
		static sf::Vector2f PointToSfVector(const PointF& point) { return { point.x, point.y }; }

		static sf::IntRect RectToSfRect(const Rect& rectangle) { return { rectangle.x, rectangle.y, rectangle.w, rectangle.h }; }
		static sf::FloatRect RectToSfRect(const RectF& rectangle) { return { rectangle.x, rectangle.y, rectangle.w, rectangle.h }; }
	};

	class SfmlRenderObject final : public IRenderObject
	{
	public:
		SfmlRenderObject() = default;
		~SfmlRenderObject() = default;

	public:
		void Update(float deltaTime) override;

	public:
		sf::Sprite& GetSprite() { return _sprite; }
		const sf::Sprite& GetConstSprite() const { return _sprite; }

	private:
		sf::Sprite _sprite;
	};

	class SfmlRenderObjectBuilder final : public IRenderObjectBuilder
	{
	public:
		SfmlRenderObjectBuilder() = default;
		~SfmlRenderObjectBuilder() = default;

	public:
		IRenderObjectBuilder& SetTexture(std::string_view filePath) override;
		IRenderObjectBuilder& SetTextureRect(const Rect& rectangle) override;
		IRenderObjectBuilder& SetPosition(const PointF& position) override;
		IRenderObjectBuilder& SetScale(const PointF& factors) override;
		IRenderObjectBuilder& SetRotation(float rotation) override;
		IRenderObjectBuilder& Create() override;
		IRenderObjectPtr GetPtr() const override;

	private:
		std::string _textureFilePath;
		Rect _rectangle { 0, 0, 32, 32 };
		PointF _position { 0, 0 };
		PointF _factors { 1.f, 1.f };
		float _rotation = 0;
		SfmlRenderObjectPtr _object;
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
		bool IsClosed() const override;
		void Clear() override;
		void ExtractEvents() override;
		void Update(float deltaTime) override;
		IRenderObjectPtr AddRenderObject(const IRenderObjectBuilder& builder) override;
		void RemoveRenderObject(IRenderObjectPtr object) override;
		bool HasRenderObject(IRenderObjectPtr object) const override;
		void Draw(IRenderObject* object) const override;
		void Display() override;

	private:
		ObjectsList::const_iterator GetConstObjectIterator(SfmlRenderObjectPtr object) const;

	private:
		std::unique_ptr<sf::RenderWindow> _windowPtr; 
		ObjectsList _objects;
	};
}

#endif // _SFML_RENDER_HEADER_
