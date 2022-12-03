#ifndef _TEXTURE_RESOURCE_HEADER_
#define _TEXTURE_RESOURCE_HEADER_

#include <TinyEngine/Core/Assets/Resources/Resource.hpp>
#include <TinyEngine/Core/Forwards.hpp>

#include "raylib-cpp.hpp"

#include <string>
#include <memory>

namespace TinyEngine
{
	class TextureResource final : public Resource
	{
	public:
		TextureResource() = default;
		~TextureResource() = default;

	public:
		void LoadFromFile(std::string_view filePath);

		raylib::Texture2D& GetTexture2D() { return _texture2D; }

	private:
		raylib::Texture2D _texture2D;
	};
}

#endif // _TEXTURE_RESOURCE_HEADER_
