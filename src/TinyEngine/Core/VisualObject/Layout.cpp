#include "Layout.hpp"

#include <TinyEngine/Core/VisualObject/Transform.hpp>

#include <vector>

namespace TinyEngine
{
    void Layout::SetTransform(const std::shared_ptr<Transform>& transform)
    {
        _transform = transform;
    }

    void VerticalLayout::Recalculate()
    {
        auto transform = GetTransform();
        if (!transform)
        {
            return;
        }

        const auto& attached = transform->GetAttached();
        if (attached.size() < 1)
        {
            return;
        }

        std::vector<RRectangle> rectangles;
        for (const auto& attachedTransform : attached)
        {
            rectangles.push_back(attachedTransform->GetRectangle());
        }

        int index = 0;
        float rectanglesHalfHeight = 0.f;
        float firstRectangleHalfHeight = 0.f;
        for (const auto& rectangle : rectangles)
        {
            rectanglesHalfHeight += rectangle.height / 2.f;

            if (index == 0)
            {
                firstRectangleHalfHeight = rectangle.height / 2.f;
            }

            ++index;
        }

        auto basePosition = transform->GetPosition();
        basePosition.y -= rectanglesHalfHeight;
        basePosition.y += firstRectangleHalfHeight;

        std::vector<RVector2> newPositions;
        index = 0;
        for (const auto& rectangle : rectangles)
        {
            auto newRectanglePosition = basePosition;
            newRectanglePosition.y += rectangle.height * static_cast<float>(index);

            newPositions.push_back(newRectanglePosition);
            ++index;
        }

        index = 0;
        for (const auto& attached : GetTransform()->GetAttached())
        {
            attached->SetPosition(newPositions[index]);
            ++index;
        }
    }
}
