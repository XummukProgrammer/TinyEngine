#include "TextureResource.hpp"

namespace TinyEngine
{
	void TextureResource::LoadFromFile(std::string_view filePath)
	{
		_texture.loadFromFile(std::string{filePath});
	}

	void TextureResource::SetRepeated(bool isRepeated)
	{
		_texture.setRepeated(isRepeated);
	}

	void TextureResource::SetSmooth(bool isSmooth)
	{
		_texture.setSmooth(isSmooth);
	}

	void TextureResource::SetSrgb(bool isSrgb)
	{
		_texture.setSrgb(isSrgb);
	}
}
