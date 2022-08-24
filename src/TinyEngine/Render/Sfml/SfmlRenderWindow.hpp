#ifndef _SFML_RENDER_WINDOW_HEADER_
#define _SFML_RENDER_WINDOW_HEADER_

#include <TinyEngine/Render/IRenderWindow.hpp>

#include <SFML/Graphics.hpp>

namespace TinyEngine
{
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

#endif // _SFML_RENDER_WINDOW_HEADER_
