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
	while (_renderWindow.isOpen()) {
		sf::Event event;
		while (_renderWindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				_renderWindow.close();
			}
		}

		_renderWindow.clear();
		onUpdate();
		_renderWindow.display();
	}
}

}
