#ifndef _VISUAL_OBJECT_HEADER_
#define _VISUAL_OBJECT_HEADER_

#include <TinyEngine/Core/VisualObject/Transform.hpp>

#include <raylib-cpp.hpp>

namespace TinyEngine
{
	class VisualObject : public TinyEngine::Transform
	{
	public:
		void Load(std::string_view path);
		
		void Draw() override;

	private:
		RTexture _texture;
	};
}

#endif // _VISUAL_OBJECT_HEADER_
