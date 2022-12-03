#include "TextureResource.hpp"

namespace TinyEngine
{
	void TextureResource::Unload()
	{
		if (IsCreate())
		{
			UnloadTexture(_info->texture);
			_info.reset();
		}
	}

	bool TextureResource::IsCreate() const
	{
		return _info != nullptr;
	}

	void TextureResource::LoadFromFile(std::string_view filePath)
	{
		auto texture = LoadTexture(filePath.data());
		_info = std::make_unique<Info>(std::move(texture));
	}
}
