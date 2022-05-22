#include "SFMLWindow.hpp"

#include <TinyEngine/Graphics/SFML/SFMLGraphics.hpp>

#include <SFML/Graphics.hpp>

namespace TE
{

CSFMLWindow::CSFMLWindow(const CData& data)
	: _renderWindow(sf::VideoMode(data.width, data.height), data.title)
{
	_renderWindow.setFramerateLimit(data.maxFramerate);
	_renderWindow.setVerticalSyncEnabled(false);
}

void CSFMLWindow::setPosition(IPointIntRef pointRef)
{ 
	auto& point = pointRef.get();
	_renderWindow.setPosition({ point.getX(), point.getY() });
}

void CSFMLWindow::getPosition(IPointIntRef pointRef) const
{ 
	auto&& position = _renderWindow.getPosition();
	pointRef.get().setPoint(position.x, position.y);
}

void CSFMLWindow::setSize(IPointUnsignedRef pointRef)
{ 
	auto& point = pointRef.get();
	_renderWindow.setSize({ point.getX(), point.getY() });
}

void CSFMLWindow::getSize(IPointUnsignedRef pointRef) const
{ 
	auto&& size = _renderWindow.getSize();
	pointRef.get().setPoint(size.x, size.y);
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
