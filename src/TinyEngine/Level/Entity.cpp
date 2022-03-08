#include "Entity.hpp"

#include <TinyEngine/Core/Context.hpp>
#include <TinyEngine/Level/Component.hpp>

namespace TinyEngine::Level
{
	void Entity::SetContext(const WeakContextPtr& weakContext)
	{ 
		_weakContext = weakContext;
	}

	void Entity::OnUpdate()
	{ 
		auto&& context = _weakContext.lock();
		if (!context)
		{
			return;
		}

		for (const auto& component : _components)
		{
			component->OnUpdate(context);
		}
	}

	void Entity::AddBaseComponent(const ComponentPtr& component)
	{ 
		_components.push_back(component);
		component->OnCreate(_weakContext.lock());
	}
}
