#include "Component.hpp"

namespace TinyEngine::Level
{
    bool Component::IsValid() const
    {
        return !IsRemoved();
    }

    void Component::Remove()
    { 
        _isRemoved = true;
    }

    bool Component::IsRemoved() const
    {
        return _isRemoved;
    }
}
