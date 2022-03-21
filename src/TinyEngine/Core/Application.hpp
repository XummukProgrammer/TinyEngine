#ifndef _APPLICATION_HEADER_
#define _APPLICATION_HEADER_

#include "Window.hpp"

#include <string>

namespace TinyEngine
{
	class Application final
	{
	public:
		Application() = default;
		~Application() = default;

	public:
		// Был совершён вход в приложение.
		void OnEntry();
		// Был совершён выход из приложения.
		void OnQuit();

	public:
		void SetName(std::string_view name);
		const std::string& GetName() const { return _name; }

		void SetVersion(std::string_view version) { _version = version; }
		const std::string& GetVersion() const { return _version; }

		Window& GetWindow() { return _window; }
		const Window& GetConstWindow() const { return _window; }

	public:
		// Запустить окно (Перехватывает управления у класса Application).
		void ExecWindow();

	private:
		void OnWindowUpdate();
		void OnWindowDraw(sf::RenderWindow& window);
		void OnWindowEvent(sf::Event& event);

	private:
		// Название приложения.
		std::string _name = "TinyEngine";
		// Версия приложения.
		std::string _version = "1.0.0_alpha";

		// Окно приложения.
		Window _window;
	};
}

#endif // _APPLICATION_HEADER_
