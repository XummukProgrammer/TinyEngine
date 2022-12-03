#include "TextureResource.hpp"

namespace TinyEngine
{
	void TextureResource::LoadFromFile(std::string_view filePath)
	{
		_texture2D.Load(std::string{filePath});
	}
}
