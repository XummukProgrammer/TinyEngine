#include "LightComponent.hpp"

#include <TinyEngine/Common/Components/TransformComponent.hpp>

#include <TinyEngine/Level/Entity.hpp>

#include <TinyEngine/Render/RenderManager.hpp>
#include <TinyEngine/Render/Layers.hpp>
#include <TinyEngine/Render/ObjectsLayer.hpp>
#include <TinyEngine/Render/LightObject.hpp>

namespace TinyEngine::Common
{
	LightComponent::LightComponent()
		: _lightObject(std::make_shared<Render::LightObject>())
	{ 
	}

	void LightComponent::OnInit()
	{ 
		_weakTransformComponent = GetEntity()->GetComponent<TransformComponent>();

		_objectsLayer->AddObject(_lightObject);
	}

	void LightComponent::OnDeinit()
	{ 
		_objectsLayer->RemoveObject(_lightObject);
		_lightObject.reset();
	}

	void LightComponent::OnUpdate()
	{ 
		if (auto transformComponent = _weakTransformComponent.lock())
		{
			_lightObject->SetPosition(transformComponent->GetPosition());
		}
	}

	void LightComponent::SetObjectsLayer(const ObjectsLayerPtr& objectsLayer)
	{
		_objectsLayer = objectsLayer;
	}

	LightComponent::LightObjectPtr LightComponent::GetLightObject() const
	{
		return _lightObject;
	}
}
