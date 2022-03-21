#ifndef _WINDOW_HEADER_
#define _WINDOW_HEADER_

#include <SFML/Graphics.hpp>

#include <string>
#include <functional>

namespace TinyEngine
{
	class Window final
	{
	public:
		using DefaultHandler = std::function<void()>;
		using DrawHandler = std::function<void(sf::RenderWindow& window)>;
		using EventHandler = std::function<void(sf::Event& event)>;

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
		void SetUpdateHandler(DefaultHandler handler) { _updateHandler = handler; }
		void SetDrawHandler(DrawHandler handler) { _drawHandler = handler; }
		void SetEventHandler(EventHandler handler) { _eventHandler = handler; }

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

		// Обработчик при обновлении окна.
		DefaultHandler _updateHandler;
		// Обработчик при отрисовке окна.
		DrawHandler _drawHandler;
		// Обработчик при срабатывании события окна.
		EventHandler _eventHandler;
	};
}

#endif // _WINDOW_HEADER_
