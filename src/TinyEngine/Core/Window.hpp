#ifndef _WINDOW_HEADER_
#define _WINDOW_HEADER_

#include <SFML/Graphics.hpp>

#include <string>
#include <functional>

#include <TinyEngine/Events/Publisher.hpp>

namespace TinyEngine
{
	class UpdateEventParameters final : public EventParameters
	{
	public:
		UpdateEventParameters() = default;
		~UpdateEventParameters() = default;
	};

	class DrawEventParameters : public EventParameters
	{
	public:
		DrawEventParameters(sf::RenderWindow& window)
			: window(window)
		{}
		~DrawEventParameters() = default;

	public:
		sf::RenderWindow& window;
	};

	class SFEventEventParameters final : public EventParameters
	{
	public:
		SFEventEventParameters(sf::Event& event)
			: event(event)
		{}
		~SFEventEventParameters() = default;

	public:
		sf::Event& event;
	};

	class Window final
	{
	public:
		DECLARE_EVENT(UpdateEventParameters, Update)
		DECLARE_EVENT(DrawEventParameters, Draw)
		DECLARE_EVENT(SFEventEventParameters, SFEvent)

	public:
		Window() = default;
		~Window() = default;

	public:
		// Был совершён вход в приложение.
		void OnAppEntry();
		// Был совершён выход из приложения.
		void OnAppQuit();

	public:
		void SetTitle(std::string_view title) { _title = title; }
		const std::string& GetTitle() const { return _title; }

		void SetWidth(unsigned width) { _width = width; }
		unsigned GetWidth() const { return _width; }

		void SetHeight(unsigned height) { _height = height; }
		unsigned GetHeight() const { return _height; }

	public:
		// Создать окно.
		void Create();
		// Уничтожить окно.
		void Destroy();

	public:
		// Запустить окно.
		void Exec();

	private:
		void OnUpdate();
		void OnDraw();
		void OnEvent(sf::Event& event);

	private:
		// Заголовок окна.
		std::string _title = "TinyEngine";
		// Ширина окна.
		unsigned _width = 800;
		// Высота окна.
		unsigned _height = 600;

		// Окно.
		sf::RenderWindow* _renderWindow = nullptr;
	};
}

#endif // _WINDOW_HEADER_
