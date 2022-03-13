#ifndef _ENTITY_HEADER_
#define _ENTITY_HEADER_

#include <TinyEngine/Level/Component.hpp>

#include <memory>
#include <vector>

namespace TinyEngine::Level
{
	class Component;

	class Entity final
	{
	public:
		using ComponentPtr = std::shared_ptr<Component>;

	public:
		Entity() = default;
		~Entity() = default;

	public:
		void OnInit();
		void OnDeinit();

		void OnUpdate();

	public:
		template<typename T>
		void AddComponent();

		template<typename T>
		std::shared_ptr<T> GetComponent() const;

		template<typename T>
		void RemoveComponent();

		void RemoveComponents();

		bool IsValid() const;

		void Remove();
		bool IsRemoved() const;

	private:
		void AddBaseComponent(const ComponentPtr& component);

		void TryRemoveComponents();

	private:
		std::vector<ComponentPtr> _components;
		bool _isRemoved = false;
		bool _isRemovedComponents = false;
	};

	template<typename T>
	void Entity::AddComponent()
	{ 
		AddBaseComponent(std::make_shared<T>());
	}

	template<typename T>
	std::shared_ptr<T> Entity::GetComponent() const
	{
		for (const auto& component : _components)
		{
			if (auto castedComponent = std::dynamic_pointer_cast<T>(component))
			{
				return castedComponent;
			}
		}

		return nullptr;
	}

	template<typename T>
	void Entity::RemoveComponent()
	{ 
		if (auto component = GetComponent<T>())
		{
			component->Remove();
		}
	}
}

#endif // _ENTITY_HEADER_
