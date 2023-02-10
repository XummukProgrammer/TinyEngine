#include "VisualObject.hpp"

namespace TinyEngine
{
    void VisualObject::Load(std::string_view path)
    {
        _texture.Load(path.data());
    }

    void VisualObject::Draw()
    {
        auto position = GetPosition();
        const auto size = _texture.GetSize();
        position.x -= size.x / 2.f;
        position.y -= size.y / 2.f;

        _texture.Draw(position);

        TinyEngine::Transform::Draw();
    }
}
