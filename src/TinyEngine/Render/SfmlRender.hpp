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

	class SfmlRenderObjectBuilder final
	{
	public:
		SfmlRenderObjectBuilder() = default;
		~SfmlRenderObjectBuilder() = default;

	public:
		SfmlRenderObjectBuilder& Create();
		SfmlRenderObjectBuilder& SetTexture(const sf::Texture& texture);
		SfmlRenderObjectBuilder& SetTextureRect(const sf::IntRect& rectangle);
		SfmlRenderObjectBuilder& SetPosition(const sf::Vector2f& position);
		SfmlRenderObjectBuilder& SetScale(const sf::Vector2f& factors);
		SfmlRenderObjectBuilder& SetRotation(float rotation);
		SfmlRenderObjectPtr GetPtr() const;

	private:
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
		void AddRenderObject(IRenderObjectPtr object) override;
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
