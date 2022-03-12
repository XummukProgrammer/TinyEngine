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

	void Entity::OnDeinit()
	{ 
		auto&& context = _weakContext.lock();

		for (const auto& component : _components)
		{
			component->OnDeinit(context);
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

	void Entity::RemoveComponents()
	{ 
		_isRemovedComponents = true;
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

		auto onRemoveComponent = [context](const auto& component)
		{
			component->OnDeinit(context);
		};

		if (_isRemovedComponents)
		{
			for (const auto& component : _components)
			{
				onRemoveComponent(component);
			}

			_components.clear();
			_isRemovedComponents = false;

			return;
		}

		for (auto it = _components.begin(); it != _components.end();)
		{
			auto& component = *it;

			if (component->IsRemoved())
			{
				onRemoveComponent(component);

				it = _components.erase(it);
			}
			else
			{
				++it;
			}
		}
	}
}
