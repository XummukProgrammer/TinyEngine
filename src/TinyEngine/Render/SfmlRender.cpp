#include "SfmlRender.hpp"

namespace TinyEngine
{
	void SfmlRenderObject::Update(float deltaTime)
	{
	}

	void SfmlRenderObject::Draw(const IRenderWindow* window) const
	{

	}

	void SfmlRenderWindow::Create(const RenderWindowSettings& windowSettings)
	{
		_windowPtr = std::make_unique<sf::RenderWindow>(sf::VideoMode(windowSettings.width, windowSettings.height), windowSettings.title);
		_windowPtr->setFramerateLimit(windowSettings.maxFramerate);
		_windowPtr->setVerticalSyncEnabled(false);
	}

	bool SfmlRenderWindow::IsClosed() const
	{
		return !_windowPtr->isOpen();
	}

	void SfmlRenderWindow::Clear()
	{
		_windowPtr->clear();
	}

	void SfmlRenderWindow::ExtractEvents()
	{
		sf::Event event;
		while (_windowPtr->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				_windowPtr->close();
			}
		}
	}

	void SfmlRenderWindow::Update()
	{
	}

	void SfmlRenderWindow::AddRenderObject(IRenderObjectPtr object)
	{
	}

	void SfmlRenderWindow::RemoveRenderObject(IRenderObjectPtr object)
	{
	}

	bool SfmlRenderWindow::HasRenderObject(IRenderObjectPtr object)
	{
		return false;
	}

	void SfmlRenderWindow::Draw(IRenderObject* object) const
	{
		object->Draw(this);
	}

	void SfmlRenderWindow::Display()
	{
		_windowPtr->display();
	}
}
