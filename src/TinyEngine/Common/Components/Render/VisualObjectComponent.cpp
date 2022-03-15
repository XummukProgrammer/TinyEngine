#include "VisualObjectComponent.hpp"

#include <TinyEngine/Common/Components/TransformComponent.hpp>
#include <TinyEngine/Common/Components/RectComponent.hpp>
#include <TinyEngine/Common/Components/Render/TextureComponent.hpp>

#include <TinyEngine/Level/Entity.hpp>

#include <TinyEngine/Render/RenderManager.hpp>
#include <TinyEngine/Render/Layers.hpp>
#include <TinyEngine/Render/ObjectsLayer.hpp>
#include <TinyEngine/Render/VisualObject.hpp>

namespace TinyEngine::Common
{
	VisualObjectComponent::VisualObjectComponent()
		: _visualObject(std::make_shared<Render::VisualObject>())
	{ 
	}

	void VisualObjectComponent::OnInit()
	{ 
		_weakTransformComponent = GetEntity()->GetComponent<TransformComponent>();
		_weakRectComponent = GetEntity()->GetComponent<RectComponent>();
		_weakTextureComponent = GetEntity()->GetComponent<TextureComponent>();

		_objectsLayer->AddObject(_visualObject);
	}

	void VisualObjectComponent::OnDeinit()
	{ 
		_objectsLayer->RemoveObject(_visualObject);
		_visualObject.reset();
	}

	void VisualObjectComponent::OnUpdate()
	{ 
		if (auto transformComponent = _weakTransformComponent.lock())
		{
			_visualObject->SetPosition(transformComponent->GetPosition());
			_visualObject->SetScale(transformComponent->GetScale());
			_visualObject->SetRotation(transformComponent->GetRotation());
		}

		if (auto rectComponent = _weakRectComponent.lock())
		{
			_visualObject->SetRect(rectComponent->GetRect());
		}

		if (auto textureComponent = _weakTextureComponent.lock())
		{
			if (auto texture = textureComponent->GetTexture())
			{
				_visualObject->SetTexture(*texture.get());
			}
			else
			{
				_visualObject->SetTexture(sf::Texture());
			}
		}
	}

	void VisualObjectComponent::SetObjectsLayer(const ObjectsLayerPtr& objectsLayer)
	{ 
		_objectsLayer = objectsLayer;
	}

	VisualObjectComponent::VisualObjectPtr VisualObjectComponent::GetVisualObject() const
	{
		return _visualObject;
	}
}
