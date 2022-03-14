#ifndef _COMPONENT_HEADER_
#define _COMPONENT_HEADER_

#include <memory>

namespace TinyEngine::Level
{
	class Entity;

	class Component
	{
	public:
		using EntityPtr = std::shared_ptr<Entity>;
		using WeakEntityPtr = std::weak_ptr<Entity>;

	public:
		Component() = default;
		virtual ~Component() = default;

	public:
		virtual void OnInit() {}
		virtual void OnDeinit() {}

		virtual void OnUpdate() {}

	public:
		void SetEntity(const WeakEntityPtr& weakEntity);
		EntityPtr GetEntity() const;

		bool IsValid() const;

		void Remove();
		bool IsRemoved() const;

	private:
		bool _isRemoved = false;
		WeakEntityPtr _weakEntity;
	};
}

#endif // _COMPONENT_HEADER_
