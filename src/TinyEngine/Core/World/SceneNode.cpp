#include "SceneNode.hpp"

namespace TinyEngine
{
    SceneNodeSharedPtr SceneNode::GetParent() const
    {
        return _parent;
    }

    const std::vector<SceneNodeSharedPtr>& SceneNode::GetChildren() const
    {
        return _children;
    }
}
