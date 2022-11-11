#ifndef _SCENE_NODE_HEADER_
#define _SCENE_NODE_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Data/Meta/MetaDefines.hpp>
#include <TinyEngine/Core/World/Entity.hpp>

namespace TinyEngine
{
	class SceneNode final : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(SceneNode)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_parent, "Parent", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_children, "Children", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_entity, "Entity", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		SceneNode() = default;
		~SceneNode() = default;

	public:
		SceneNodeSharedPtr GetParent() const;
		const std::vector<SceneNodeSharedPtr>& GetChildren() const;

	public:
		SceneNodeSharedPtr _parent;
		std::vector<SceneNodeSharedPtr> _children;
		EntitySharedPtr _entity;
	};
}

#endif // _SCENE_NODE_HEADER_
