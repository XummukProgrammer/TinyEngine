#include "SFMLWindow.hpp"
#include <iostream>

namespace te
{

CSFMLWindow::CSFMLWindow(const CData& data)
	: _data(data)
{}

void CSFMLWindow::create()
{ 
	_renderWindowPtr = std::make_unique<sf::RenderWindow>(sf::VideoMode(_data.width, _data.height), _data.title);
}

void CSFMLWindow::destroy()
{ 
	_renderWindowPtr.reset();
}

void CSFMLWindow::exec()
{ 
	auto& renderWindowRef = *_renderWindowPtr.get();

	while (renderWindowRef.isOpen()) {
		sf::Event event;
		while (renderWindowRef.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				renderWindowRef.close();
			}
		}

		renderWindowRef.clear();
		renderWindowRef.display();
	}
}

}
