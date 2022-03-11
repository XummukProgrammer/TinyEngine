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
		TryRemoveComponents();

		auto&& context = _weakContext.lock();

		for (const auto& component : _components)
		{
			if (component->IsValid())
			{
				component->OnUpdate(context);
			}
		}
	}

	bool Entity::IsValid() const
	{
		return !IsRemoved();
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

	void Entity::TryRemoveComponents()
	{ 
		auto&& context = _weakContext.lock();

		for (auto it = _components.begin(); it != _components.end();)
		{
			auto& component = *it;

			if (component->IsRemoved())
			{
				component->OnDeinit(context);

				it = _components.erase(it);
			}
			else
			{
				++it;
			}
		}
	}
}
