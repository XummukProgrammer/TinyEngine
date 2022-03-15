#include "ObjectsLayerComponent.hpp"

#include <TinyEngine/Render/Render.hpp>
#include <TinyEngine/Render/Layers.hpp>
#include <TinyEngine/Render/ObjectsLayer.hpp>

namespace TinyEngine::Common
{
	ObjectsLayerComponent::ObjectsLayerComponent()
		: _objectsLayer(std::make_shared<Render::ObjectsLayer>())
	{ 
	}

	void ObjectsLayerComponent::OnInit()
	{ 
		Render::Render::GetInstance().GetLayers()->AddLayer(_key, _objectsLayer);
	}

	void ObjectsLayerComponent::OnDeinit()
	{
		Render::Render::GetInstance().GetLayers()->RemoveLayer(_key);
		_objectsLayer.reset();
	}

	void ObjectsLayerComponent::SetKey(std::string_view key)
	{ 
		_key = key;
	}

	const std::string& ObjectsLayerComponent::GetKey() const
	{
		return _key;
	}

	ObjectsLayerComponent::ObjectsLayerPtr ObjectsLayerComponent::GetObjectsLayer() const
	{
		return _objectsLayer;
	}
}
