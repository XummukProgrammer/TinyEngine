#include "ILayer.hpp"

namespace TinyEngine::Render
{
    bool ILayer::IsValid() const
    {
        return !IsRemoved();
    }

    void ILayer::Remove()
    { 
        _isRemoved = true;
    }

    bool ILayer::IsRemoved() const
    {
        return _isRemoved;
    }
}
