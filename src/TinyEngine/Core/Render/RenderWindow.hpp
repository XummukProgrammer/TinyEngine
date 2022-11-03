#ifndef _INTERFACE_RENDER_WINDOW_HEADER_
#define _INTERFACE_RENDER_WINDOW_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Data/Singleton.hpp>
#include <TinyEngine/Core/Render/RenderObject.hpp>
#include <TinyEngine/Core/Render/RenderWindowSettings.hpp>

#ifdef TINY_ENGINE_USE_SFML
#include <SFML/Graphics.hpp>
#endif

#include <functional>

namespace TinyEngine
{
	class RenderWindow final : public Singleton<RenderWindow>
	{
	public:
		using EventReceivedCallback = std::function<void()>;

	public:
		RenderWindow();
		~RenderWindow();

	public:
		void Create(const RenderWindowSettings& windowSettings);
		bool IsClosed() const;
		void Clear();
		void ExtractEvents();
		void Draw(RenderObject* object) const;
		void Display();
		void Close();

		void ResetClock();
		void UpdateClock();
		float GetDeltaTime() const;
	
		void SetOnEventReceived(const EventReceivedCallback& callback) { _onEventReceived = callback; }

#ifdef TINY_ENGINE_USE_SFML
		sf::RenderWindow* GetRenderWindow() const { return _renderWindow; }

		sf::Event& GetEvent() { return _event; }
		const sf::Event& GetConstEvent() const { return _event; }
#endif

	private:
		void OnEventReceived() { if (_onEventReceived) _onEventReceived(); }

	private:
		EventReceivedCallback _onEventReceived;

#ifdef TINY_ENGINE_USE_SFML
		sf::RenderWindow* _renderWindow = nullptr;
		sf::Event _event;
#endif
	};
};

#endif // _INTERFACE_RENDER_WINDOW_HEADER_
