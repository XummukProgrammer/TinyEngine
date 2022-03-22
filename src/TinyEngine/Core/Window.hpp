﻿#ifndef _WINDOW_HEADER_
#define _WINDOW_HEADER_

#include <SFML/Graphics.hpp>

#include <string>
#include <functional>

#include <TinyEngine/Events/Publisher.hpp>

namespace TinyEngine
{
	// Параметры для события "Обновление"
	class UpdatedEventParameters final : public EventParameters
	{
	public:
		UpdatedEventParameters() = default;
		~UpdatedEventParameters() = default;
	};

	// Параметры для события "Отрисовка"
	class DrawedEventParameters final : public EventParameters
	{
	public:
		DrawedEventParameters(sf::RenderWindow& window)
			: window(window)
		{}
		~DrawedEventParameters() = default;

	public:
		sf::RenderWindow& window;
	};

	// Параметры для события "Событие"
	class EventedParameters final : public EventParameters
	{
	public:
		EventedParameters(sf::Event& event)
			: event(event)
		{}
		~EventedParameters() = default;

	public:
		sf::Event& event;
	};

	// Класс работает с окном приложения.
	class Window final
	{
		// Объявляем события окна.
		DECLARE_EVENT(UpdatedEventParameters, Updated)
		DECLARE_EVENT(DrawedEventParameters, Drawed)
		DECLARE_EVENT(EventedParameters, Evented)

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
