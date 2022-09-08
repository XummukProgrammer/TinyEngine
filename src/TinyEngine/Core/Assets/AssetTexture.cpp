#include "AssetTexture.hpp"

#include <TinyEngine/Core/FileSystem.hpp>

namespace TinyEngine
{
	void AssetSfmlTexture::OnAssetLoad()
	{
		const std::string path = FileSystem::GetInstance()->BuildPath(DirType::Assets, GetPath());

		_texture.loadFromFile(path);
		_texture.setRepeated(IsRepeated());
		_texture.setSmooth(IsSmooth());
		_texture.setSrgb(IsSrgb());
	}

	void AssetSfmlTexture::LoadTexture(Texture& texture)
	{
		texture.data = &_texture;
	}
}
