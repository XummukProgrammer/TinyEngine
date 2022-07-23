#include "SfmlRender.hpp"

namespace TinyEngine
{
	void SfmlRenderObject::Update(float deltaTime)
	{
	}

	IRenderObjectBuilder& SfmlRenderObjectBuilder::SetTexture(std::string_view filePath)
	{
		_textureFilePath = filePath;
		return *this;
	}

	IRenderObjectBuilder& SfmlRenderObjectBuilder::SetTextureRect(const Rect& rectangle)
	{
		_rectangle = rectangle;
		return *this;
	}

	IRenderObjectBuilder& SfmlRenderObjectBuilder::SetPosition(const PointF& position)
	{
		_position = position;
		return *this;
	}

	IRenderObjectBuilder& SfmlRenderObjectBuilder::SetScale(const PointF& factors)
	{
		_factors = factors;
		return *this;
	}

	IRenderObjectBuilder& SfmlRenderObjectBuilder::SetRotation(float rotation)
	{
		_rotation = rotation;
		return *this;
	}

	IRenderObjectBuilder& SfmlRenderObjectBuilder::Create()
	{
		_object = std::make_shared<SfmlRenderObject>();
		auto& sprite = _object->GetSprite();
		sprite.setTexture(sf::Texture()); // TODO: Get from Asset Manager
		sprite.setTextureRect(SfmlRenderUtils::RectToSfRect(_rectangle));
		sprite.setPosition(SfmlRenderUtils::PointToSfVector(_position));
		sprite.setScale(SfmlRenderUtils::PointToSfVector(_factors));
		sprite.setRotation(_rotation);
		
		return *this;
	}

	IRenderObjectPtr SfmlRenderObjectBuilder::GetPtr() const
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

	IRenderObjectPtr SfmlRenderWindow::AddRenderObject(const IRenderObjectBuilder& builder)
	{
		auto object = std::dynamic_pointer_cast<SfmlRenderObject>(builder.GetPtr());
		_objects.push_back(object);
		return object;
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
