#include "Transform.hpp"

#include <TinyEngine/Core/Application/Application.hpp>

#include <raylib-cpp.hpp>

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
                Recalculate();
                break;
            }
        }
    }

    void Transform::SetLocalPosition(const RVector2& position)
    {
        _localPosition = position;
        Recalculate();
    }

    RRectangle Transform::GetRectangle() const
    {
        auto rectangle = RRectangle();

        if (_anchor)
        {
            rectangle = _anchor->GetRectangle(GetPosition(), _localScale);
        }
        else
        {
            const float scalePixelCoef = Application::GetSingleton().GetContext().GetScalePixelCoef();
            auto rectanglePosition = GetPosition();
            rectanglePosition.x -= (_localScale * scalePixelCoef / 2.f).x;
            rectanglePosition.y -= (_localScale * scalePixelCoef / 2.f).y;

            rectangle.SetPosition(rectanglePosition);
            rectangle.SetSize(_localScale * scalePixelCoef);
        }

        return rectangle;
    }

    void Transform::SetLocalScale(const RVector2& scale)
    {
        _localScale = scale;
        Recalculate();
    }

    void Transform::SetLayout(const std::shared_ptr<Layout>& layout)
    {
        _layout = layout;
        _layout->SetTransform(shared_from_this());
    }

    bool Transform::IsControlledByLayout() const
    {
        if (auto parent = GetParent())
        {
            if (parent->GetLayout())
            {
                return true;
            }
        }
        return false;
    }

    void Transform::Draw()
    {
        if (Application::GetSingleton().GetContext().IsDrawGizmos())
        {
            OnDrawGizmos();
        }

        for (const auto& attached : _attached)
        {
            attached->Draw();
        }
    }

    void Transform::OnDrawGizmos()
    {
        RRectangle rectangle = GetRectangle();
        rectangle.DrawLines(RColor::Red());

        DrawCircle(GetPosition().x, GetPosition().y, 2, RColor::Red());
    }

    void Transform::Recalculate()
    {
        auto parentPosition = RVector2();

        if (auto parent = GetParent())
        {
            parentPosition = parent->GetPosition();
        }

        if (!IsControlledByLayout())
        {
            _position = _localPosition + parentPosition;
        }

        if (_layout)
        {
            _layout->Recalculate();
        }

        for (const auto& attached : _attached)
        {
            attached->Recalculate();
        }  
    }
}
