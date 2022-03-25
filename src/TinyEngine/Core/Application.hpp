#ifndef _APPLICATION_HEADER_
#define _APPLICATION_HEADER_

#include "Window.hpp"
#include <TinyEngine/Assets/AllAssets.hpp>

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
		void SetConsoleArgumentCount(int argc) { _consoleArgumentCount = argc; }
		int GetConsoleArgumentCount() const { return _consoleArgumentCount; }

		void SetConsoleArguments(char** argv) { _consoleArguments = argv; }
		char** GetConsoleArguments() const { return _consoleArguments; }

		void SetName(std::string_view name);
		const std::string& GetName() const { return _name; }

		void SetVersion(std::string_view version) { _version = version; }
		const std::string& GetVersion() const { return _version; }

		Window& GetWindow() { return _window; }
		const Window& GetConstWindow() const { return _window; }

		AllAssets& GetAllAssets() { return _allAssets; }
		const AllAssets& GetConstAllAssets() const { return _allAssets; }

	public:
		// Запустить окно (Перехватывает управления у класса Application).
		void ExecWindow();

	private:
		void OnWindowUpdated(UpdatedEventParameters& params);
		void OnWindowDrawed(DrawedEventParameters& params);
		void OnWindowEvented(EventedParameters& params);

		void OnGuiRenderer(GuiRenderedEventParameters& params);

	private:
		// Название приложения.
		std::string _name = "TinyEngine";
		// Версия приложения.
		std::string _version = "1.0.0_alpha";

		// Окно приложения.
		Window _window;

		// Все ассеты.
		AllAssets _allAssets;

		// Кол-во аргументов командной строки.
		int _consoleArgumentCount = 0;
		// Аргументы командной строки.
		char** _consoleArguments;
	};
}

#endif // _APPLICATION_HEADER_
