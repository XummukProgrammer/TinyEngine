#include "SfmlRender.hpp"

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

	IRenderObjectBuilder& SfmlRenderObjectBuilder::SetTexture(std::string_view assetId)
	{
		_textureAssetId = assetId;
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
		_object->SetTexture(_textureAssetId);
		_object->SetTextureRect(_rectangle);
		_object->SetPosition(_position);
		_object->SetScale(_factors);
		_object->SetRotation(_rotation);

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
