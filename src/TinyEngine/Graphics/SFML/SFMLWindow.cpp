#include "SFMLWindow.hpp"

#include <SFML/Graphics.hpp>

namespace te
{

CSFMLWindow::CSFMLWindow(const CData& data)
	: _renderWindow(sf::VideoMode(data.width, data.height), data.title)
{
	_renderWindow.setFramerateLimit(data.maxFramerate);
	_renderWindow.setVerticalSyncEnabled(false);
}

void CSFMLWindow::exec()
{ 
	_clock.restart();

	while (_renderWindow.isOpen()) {
		_time = _clock.restart();

		sf::Event event;
		while (_renderWindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				_renderWindow.close();
			}
		}

		onUpdate(_time.asSeconds());

		_renderWindow.clear();
		_renderWindow.display();
	}
}

}
