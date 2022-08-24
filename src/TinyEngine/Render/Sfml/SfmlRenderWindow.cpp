#include "SfmlRenderWindow.hpp"

#include <TinyEngine/Render/Sfml/SfmlRenderObject.hpp>
#include <TinyEngine/Gui/SfmlGuiDelegate.hpp>

namespace TinyEngine
{
	void SfmlRenderWindow::Create(const RenderWindowSettings& windowSettings)
	{
		_windowPtr = std::make_unique<sf::RenderWindow>(sf::VideoMode(windowSettings.width, windowSettings.height), windowSettings.title);
		_windowPtr->setFramerateLimit(windowSettings.maxFramerate);
		_windowPtr->setVerticalSyncEnabled(false);
	}

	GuiDelegateUniquePtr SfmlRenderWindow::CreateDelegate() const
	{
		return std::make_unique<SfmlGuiDelegate>();
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
		while (_windowPtr->pollEvent(_event))
		{
			if (_event.type == sf::Event::Closed)
			{
				Close();
			}
			else
			{
				OnEventReceived();
			}
		}
	}

	void SfmlRenderWindow::Draw(IRenderObject* object) const
	{
		const auto& sprite = static_cast<SfmlRenderObject*>(object)->GetConstSprite();
		_windowPtr->draw(sprite);
	}

	void SfmlRenderWindow::Display()
	{
		_windowPtr->display();
	}

	void SfmlRenderWindow::Close()
	{
		_windowPtr->close();
	}

	void SfmlRenderWindow::ResetClock()
	{
		_clock.restart();
	}

	void SfmlRenderWindow::UpdateClock()
	{
		_deltaTime = _clock.restart();
	}
}
