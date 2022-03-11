﻿#ifndef _ENTITY_HEADER_
#define _ENTITY_HEADER_

#include <memory>
#include <vector>

namespace TinyEngine::Core
{
	class Context;
}

namespace TinyEngine::Level
{
	class Component;

	class Entity final
	{
	public:
		using ComponentPtr = std::shared_ptr<Component>;
		using WeakContextPtr = std::weak_ptr<Core::Context>;

	public:
		Entity() = default;
		~Entity() = default;

	public:
		void OnInit();
		void OnDeinit() {}

		void OnUpdate();

	public:
		void SetContext(const WeakContextPtr& weakContext);

		template<typename T>
		void AddComponent();

		bool IsValid() const;

		void Remove();
		bool IsRemoved() const;

	private:
		void AddBaseComponent(const ComponentPtr& component);

		void TryRemoveComponents();

	private:
		WeakContextPtr _weakContext;
		std::vector<ComponentPtr> _components;
		bool _isRemoved = false;
	};

	template<typename T>
	void Entity::AddComponent()
	{ 
		AddBaseComponent(std::make_shared<T>());
	}
}

#endif // _ENTITY_HEADER_
