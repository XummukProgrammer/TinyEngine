#include "VisualObjectComponent.hpp"

#include <TinyEngine/Common/Components/TransformComponent.hpp>

#include <TinyEngine/Level/Entity.hpp>

#include <TinyEngine/Render/Render.hpp>
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
