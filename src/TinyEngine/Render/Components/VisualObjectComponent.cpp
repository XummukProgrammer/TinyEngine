#include "VisualObjectComponent.hpp"

#include <TinyEngine/Render/Render.hpp>
#include <TinyEngine/Render/Layers.hpp>
#include <TinyEngine/Render/ObjectsLayer.hpp>
#include <TinyEngine/Render/VisualObject.hpp>

namespace TinyEngine::Render
{
	VisualObjectComponent::VisualObjectComponent()
		: _visualObject(std::make_shared<VisualObject>())
	{ 
	}

	void VisualObjectComponent::OnInit()
	{ 
		_objectsLayer->AddObject(_visualObject);
	}

	void VisualObjectComponent::OnDeinit()
	{ 
		_objectsLayer->RemoveObject(_visualObject);
		_visualObject.reset();
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
