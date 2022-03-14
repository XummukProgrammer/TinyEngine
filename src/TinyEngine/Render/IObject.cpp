#include "IObject.hpp"

namespace TinyEngine::Render
{
    bool IObject::IsValid() const
    {
        return !IsRemoved();
    }

    void IObject::Remove()
    { 
        _isRemoved = true;
    }

    bool IObject::IsRemoved() const
    {
        return _isRemoved;
    }
}
