#include "Transform.hpp"

namespace TinyEngine
{
    void Transform::Attach(std::shared_ptr<Transform> transform)
    {
        transform->SetParent(shared_from_this());
        _attached.push_back(transform);
        Recalculate();
    }

    void Transform::Detach(std::shared_ptr<Transform> transform)
    {
        for (auto it = _attached.begin(); it != _attached.end(); ++it)
        {
            if ((*it) == transform)
            {
                _attached.erase(it);
                break;
            }
        }

        Recalculate();
    }

    void Transform::SetLocalPosition(const RVector2& position)
    {
        _localPosition = position;
        Recalculate();
    }

    void Transform::Recalculate()
    {
        auto parentPosition = RVector2();
        if (auto parent = GetParent())
        {
            parentPosition = parent->GetPosition();
        }

        _position = _localPosition + parentPosition;

        for (const auto& attached : _attached)
        {
            attached->Recalculate();
        }
    }
}
