#ifndef _ENTITY_HEADER_
#define _ENTITY_HEADER_

#include <TinyEngine/Core/Data/Meta/MetaDefines.hpp>
#include <TinyEngine/Core/World/Component.hpp>

namespace TinyEngine
{
	class Entity final : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(Entity)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_components, "Components", "Components");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		Entity() = default;
		~Entity() = default;

	public:
		void OnInit();
		void OnDeinit();
		void OnUpdate();

	public:
		template<typename T> std::shared_ptr<T> GetComponent() const;

	private:
		std::vector<ComponentSharedPtr> _components;
	};

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
		return {};
	}
}

#endif // _ENTITY_HEADER_
