#include "ObjectsLayer.hpp"

#include <TinyEngine/Render/IObject.hpp>

namespace TinyEngine::Render
{
	void ObjectsLayer::OnDraw()
	{ 
		TryRemoveObjects();

		for (const auto& object : _objects)
		{
			object->OnDraw();
		}
	}

	void ObjectsLayer::AddObject(const ObjectPtr& object)
	{ 
		_objects.push_back(object);
	}

	void ObjectsLayer::RemoveObject(const ObjectPtr& object)
	{ 
		object->Remove();
	}

	void ObjectsLayer::TryRemoveObjects()
	{ 
		for (auto it = _objects.begin(); it != _objects.end();)
		{
			auto& object = *it;

			if (object->IsRemoved())
			{
				object->OnDeinit();

				it = _objects.erase(it);
			}
			else
			{
				++it;
			}
		}
	}
}
