#include "SfmlRender.hpp"

namespace TinyEngine
{
	void SfmlRenderObject::Update(float deltaTime)
	{
	}

	SfmlRenderObjectBuilder& SfmlRenderObjectBuilder::Create()
	{
		_object = std::make_shared<SfmlRenderObject>();
		return *this;
	}

	SfmlRenderObjectBuilder& SfmlRenderObjectBuilder::SetTexture(const sf::Texture& texture)
	{
		_object->GetSprite().setTexture(texture);
		return *this;
	}

	SfmlRenderObjectBuilder& SfmlRenderObjectBuilder::SetTextureRect(const sf::IntRect& rectangle)
	{
		_object->GetSprite().setTextureRect(rectangle);
		return *this;
	}

	SfmlRenderObjectBuilder& SfmlRenderObjectBuilder::SetPosition(const sf::Vector2f& position)
	{
		_object->GetSprite().setPosition(position);
		return *this;
	}

	SfmlRenderObjectBuilder& SfmlRenderObjectBuilder::SetScale(const sf::Vector2f& factors)
	{
		_object->GetSprite().setScale(factors);
		return *this;
	}

	SfmlRenderObjectBuilder& SfmlRenderObjectBuilder::SetRotation(float rotation)
	{
		_object->GetSprite().setRotation(rotation);
		return *this;
	}

	SfmlRenderObjectPtr SfmlRenderObjectBuilder::GetPtr() const
	{
		return _object;
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

	void SfmlRenderWindow::Update(float deltaTime)
	{
		for (const auto& object : _objects)
		{
			object->Update(deltaTime);
		}
	}

	void SfmlRenderWindow::AddRenderObject(IRenderObjectPtr object)
	{
		auto castedObject = std::dynamic_pointer_cast<SfmlRenderObject>(object);
		_objects.push_back(std::move(castedObject));
	}

	void SfmlRenderWindow::RemoveRenderObject(IRenderObjectPtr object)
	{
		const auto it = GetConstObjectIterator(std::dynamic_pointer_cast<SfmlRenderObject>(object));
		if (it != _objects.end())
		{
			_objects.erase(it);
		}
	}

	bool SfmlRenderWindow::HasRenderObject(IRenderObjectPtr object) const
	{
		return GetConstObjectIterator(std::dynamic_pointer_cast<SfmlRenderObject>(object)) != _objects.end();
	}

	void SfmlRenderWindow::Draw(IRenderObject* object) const
	{
		const auto& sprite = static_cast<SfmlRenderObject*>(object)->GetConstSprite();
		_windowPtr->draw(sprite);
	}

	void SfmlRenderWindow::Display()
	{
		for (const auto& object : _objects)
		{
			Draw(object.get());
		}

		_windowPtr->display();
	}

	SfmlRenderWindow::ObjectsList::const_iterator SfmlRenderWindow::GetConstObjectIterator(SfmlRenderObjectPtr object) const
	{
		return std::find(_objects.begin(), _objects.end(), object);
	}
}
