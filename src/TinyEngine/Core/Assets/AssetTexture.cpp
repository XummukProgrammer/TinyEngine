#include "AssetTexture.hpp"

#include <TinyEngine/Core/Application.hpp>

namespace TinyEngine
{
	void AssetSfmlTexture::OnLoad()
	{
		const std::string path = FileSystem::GetInstance().BuildPath(FileSystem::DirType::Assets, GetPath());

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
