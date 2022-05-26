#include "SFMLWindow.hpp"

#include <TinyEngine/Graphics/SFML/SFMLGraphics.hpp>

#include <SFML/Graphics.hpp>

#include <pugixml.hpp>

namespace TE
{

CSFMLWindow::CSFMLWindow(const CData& data)
	: _renderWindow(sf::VideoMode(data.width, data.height), data.title)
{
	_renderWindow.setFramerateLimit(data.maxFramerate);
	_renderWindow.setVerticalSyncEnabled(false);
}

CSFMLWindow::CData CSFMLWindow::LoadDataFromFile(CPaths& paths, CPaths::Type pathType, const std::string& path)
{
	CData windowData;
	pugi::xml_document doc;

	if (!doc.load_file(paths.buildPath(pathType, path).c_str())) {
		// TODO: Добавить ассерт.
		return windowData;
	}

	// TODO: Добавить утилиты для работы с pugi.
	auto settings = doc.first_child().child("Settings");
	windowData.width = settings.attribute("width").as_uint();
	windowData.height = settings.attribute("height").as_uint();
	windowData.title = settings.attribute("title").as_string();
	windowData.maxFramerate = settings.attribute("maxFramerate").as_uint();

	return windowData;
}

void CSFMLWindow::setPosition(IPointInt* pointPtr)
{ 
	_renderWindow.setPosition({ pointPtr->getX(), pointPtr->getY() });
}

void CSFMLWindow::getPosition(IPointInt* pointPtr) const
{ 
	auto&& position = _renderWindow.getPosition();
	pointPtr->setPoint(position.x, position.y);
}

void CSFMLWindow::setSize(IPointUnsigned* pointPtr)
{ 
	_renderWindow.setSize({ pointPtr->getX(), pointPtr->getY() });
}

void CSFMLWindow::getSize(IPointUnsigned* pointPtr) const
{ 
	auto&& size = _renderWindow.getSize();
	pointPtr->setPoint(size.x, size.y);
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
		onDraw();
		_renderWindow.display();
	}
}

}
