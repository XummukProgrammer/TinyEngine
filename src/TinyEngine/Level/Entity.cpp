#include "Entity.hpp"

#include <TinyEngine/Core/Context.hpp>
#include <TinyEngine/Level/Component.hpp>

namespace TinyEngine::Level
{
	void Entity::SetContext(const WeakContextPtr& weakContext)
	{ 
		_weakContext = weakContext;
	}

	void Entity::OnInit()
	{ 
		auto&& context = _weakContext.lock();

		for (const auto& component : _components)
		{
			component->OnInit(context);
		}
	}

	void Entity::OnUpdate()
	{ 
		auto&& context = _weakContext.lock();

		for (const auto& component : _components)
		{
			component->OnUpdate(context);
		}
	}

	void Entity::Remove()
	{
		_isRemoved = true;
	}

	bool Entity::IsRemoved() const
	{
		return _isRemoved;
	}

	void Entity::AddBaseComponent(const ComponentPtr& component)
	{ 
		_components.push_back(component);
	}
}
