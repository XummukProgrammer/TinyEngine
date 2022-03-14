#include "Component.hpp"

#include <TinyEngine/Level/Entity.hpp>

namespace TinyEngine::Level
{
    void Component::SetEntity(const WeakEntityPtr& weakEntity)
    { 
        _weakEntity = weakEntity;
    }

    Component::EntityPtr Component::GetEntity() const
    {
        return _weakEntity.lock();
    }

    bool Component::IsValid() const
    {
        // TODO: В будущем оценить производительность
        return !IsRemoved() && GetEntity();
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
