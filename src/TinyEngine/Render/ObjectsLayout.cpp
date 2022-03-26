#include "ObjectsLayout.hpp"

#include <algorithm>

namespace TinyEngine
{
	void ObjectsLayout::OnWindowUpdated()
	{
		std::for_each(_objects.begin(), _objects.end(), [](IObject* object)
		{
			object->OnWindowUpdated();
		});
	}

	void ObjectsLayout::OnWindowDrawed()
	{
		std::for_each(_objects.begin(), _objects.end(), [](IObject* object)
		{
			object->OnWindowDrawed();
		});
	}

	void ObjectsLayout::AddObject(IObject* object)
	{ 
		_objects.push_back(object);
	}

	void ObjectsLayout::RemoveObject(const IObject* object)
	{ 
		auto it = std::find(_objects.begin(), _objects.end(), object);

		if (it != _objects.end())
		{
			_objects.erase(it);
		}
	}
}
