#ifndef _OBJECT_NODE_HEADER_
#define _OBJECT_NODE_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Data/Meta/MetaDefines.hpp>
#include <TinyEngine/Core/World/Entity.hpp>

namespace TinyEngine
{
	class ObjectNode final : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(ObjectNode)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_parent, "Parent", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_children, "Children", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_entity, "Entity", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		ObjectNode() = default;
		~ObjectNode() = default;

	public:
		ObjectNodeSharedPtr GetParent() const;
		const std::vector<ObjectNodeSharedPtr>& GetChildren() const;

	public:
		ObjectNodeSharedPtr _parent;
		std::vector<ObjectNodeSharedPtr> _children;
		EntitySharedPtr _entity;
	};
}

#endif // _OBJECT_NODE_HEADER_
