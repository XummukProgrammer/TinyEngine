#include "ObjectNode.hpp"

namespace TinyEngine
{
    ObjectNodeSharedPtr ObjectNode::GetParent() const
    {
        return _parent;
    }

    const std::vector<ObjectNodeSharedPtr>& ObjectNode::GetChildren() const
    {
        return _children;
    }
}
