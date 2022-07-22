#ifndef _SFML_RENDER_HEADER_
#define _SFML_RENDER_HEADER_

#include <TinyEngine/Render/Render.hpp>

#include <SFML/Graphics.hpp>

#include <memory>

namespace TinyEngine
{
	class SfmlRenderObject final : public IRenderObject
	{
	public:
		SfmlRenderObject() = default;
		~SfmlRenderObject() = default;

	public:
		void Update(float deltaTime) override;
		void Draw(const IRenderWindow* window) const override;
	};

	class SfmlRenderWindow final : public IRenderWindow
	{
	public:
		SfmlRenderWindow() = default;
		~SfmlRenderWindow() = default;

	public:
		void Create(const RenderWindowSettings& windowSettings) override;
		bool IsClosed() const override;
		void Clear() override;
		void ExtractEvents() override;
		void Update() override;
		void AddRenderObject(IRenderObjectPtr object) override;
		void RemoveRenderObject(IRenderObjectPtr object) override;
		bool HasRenderObject(IRenderObjectPtr object) override;
		void Draw(IRenderObject* object) const override;
		void Display() override;

	private:
		std::unique_ptr<sf::RenderWindow> _windowPtr; 
	};
}

#endif // _SFML_RENDER_HEADER_
