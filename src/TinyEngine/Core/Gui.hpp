#ifndef _GUI_HEADER_
#define _GUI_HEADER_

#include <TinyEngine/Events/Publisher.hpp>

#include <SFML/Graphics.hpp>

namespace TinyEngine
{
	// Параметры для события "Рендер"
	class GuiRenderedEventParameters : public EventParameters
	{
	public:
		GuiRenderedEventParameters() = default;
		~GuiRenderedEventParameters() = default;
	};

	// Класс графического интерфейса.
	class Gui final
	{
		DECLARE_EVENT(GuiRenderedEventParameters, Renderer)

	public:
		Gui() = default;
		~Gui() = default;

	public:
		void OnAppQuit();

		void OnWindowCreated(sf::RenderWindow& renderWindow);
		void OnWindowUpdated(sf::RenderWindow& renderWindow, const sf::Time& time);
		void OnWindowDrawed(sf::RenderWindow& renderWindow);
		void OnWindowEvented(sf::RenderWindow& renderWindow, sf::Event& event);
	};
}

#endif // _GUI_HEADER_
