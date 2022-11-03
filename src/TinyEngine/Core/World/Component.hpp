#ifndef _COMPONENT_HEADER_
#define _COMPONENT_HEADER_

#include <TinyEngine/Core/Data/Meta/MetaDefines.hpp>

namespace TinyEngine
{
	class Component : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(Component)
		{
		}
		TINY_ENGINE_META_CLASS_END

	public:
		Component() = default;
		virtual ~Component() = default;

	public:
		virtual void OnInit() {}
		virtual void OnDeinit() {}

		virtual void OnEnable() {}
		virtual void OnDisable() {}

		virtual void OnUpdate() {}

	public:
		void SetEntity(EntityPtr entity) { _entity = entity; }
		EntityPtr GetEntity() const { return _entity; }

	private:
		EntityPtr _entity;
	};
}

#endif // _COMPONENT_HEADER_
