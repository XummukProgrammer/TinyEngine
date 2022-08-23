#include "SfmlRender.hpp"

#include <TinyEngine/Gui/SfmlGuiDelegate.hpp>

#ifdef TINY_ENGINE_USE_SFML

namespace TinyEngine
{
	void SfmlRenderObject::Update(float deltaTime)
	{
	}

	void SfmlRenderObject::SetPosition(const PointF& position)
	{
		_sprite.setPosition(SfmlRenderUtils::PointToSfVector(position));
	}

	PointF SfmlRenderObject::GetPosition() const
	{
		return SfmlRenderUtils::SfVectorToPoint(_sprite.getPosition());
	}

	void SfmlRenderObject::SetScale(const PointF& factors)
	{
		_sprite.setScale(SfmlRenderUtils::PointToSfVector(factors));
	}

	PointF SfmlRenderObject::GetScale() const
	{
		return SfmlRenderUtils::SfVectorToPoint(_sprite.getScale());
	}

	void SfmlRenderObject::SetRotation(float rotation)
	{
		_sprite.setRotation(rotation);
	}

	float SfmlRenderObject::GetRotation() const
	{
		return _sprite.getRotation();
	}

	void SfmlRenderObject::SetTexture(std::string_view filePath)
	{
		// TODO: Get from Asset Manager
		_sprite.setTexture(sf::Texture());
	}

	void SfmlRenderObject::SetTextureRect(const Rect& rectangle)
	{
		_sprite.setTextureRect(SfmlRenderUtils::RectToSfRect(rectangle));
	}

	bool SfmlRenderObject::IsPointIntersects(const PointF& point) const
	{
		return _sprite.getGlobalBounds().contains(SfmlRenderUtils::PointToSfVector(point));
	}

	bool SfmlRenderObject::IsRectIntersects(const RectF& rectangle) const
	{
		return _sprite.getGlobalBounds().intersects(SfmlRenderUtils::RectToSfRect(rectangle));
	}

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

#endif
