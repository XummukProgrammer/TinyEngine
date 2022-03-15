#ifndef _WINDOW_HEADER_
#define _WINDOW_HEADER_

#include <TinyEngine/Utils/Singleton.hpp>

#include <SFML/Graphics/Drawable.hpp>

#include <memory>
#include <string>
#include <functional>

namespace sf
{
	class RenderWindow;
}

namespace TinyEngine::Core
{
	struct WindowInfo
	{
		unsigned width = 800;
		unsigned height = 600;
		std::string title = "TinyEngine";
		unsigned maxFramerate = 60;
		bool isVerticalSyncEnabled = false;

		void LoadFromFile();
	};

	class Window final : public Utils::Singleton<Window>
	{
	public:
		using RenderWindowPtr = std::shared_ptr<sf::RenderWindow>;
		using UpdateCallback = std::function<void()>;
		using DrawCallback = std::function<void()>;
		using EventCallback = std::function<void()>;

	public:
		Window() = default;
		~Window() = default;

	public:
		void OnExecute();

	public:
		void CreateWindow(const WindowInfo& info);

		void SetOnUpdateCallback(const UpdateCallback& callback) { _onUpdateCallback = callback; }
		void SetOnDrawCallback(const DrawCallback& callback) { _onDrawCallback = callback; }
		void SetOnEventCallback(const EventCallback& callback) { _onEventCallback = callback; }

		void Draw(const sf::Drawable& drawable);

	private:
		void OnUpdate();
		void OnDraw();
		void OnEvent();

	private:
		RenderWindowPtr _renderWindow;
		UpdateCallback _onUpdateCallback;
		DrawCallback _onDrawCallback;
		EventCallback _onEventCallback;
	};
}

#endif // _WINDOW_HEADER_
