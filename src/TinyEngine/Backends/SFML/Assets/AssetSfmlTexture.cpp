﻿#include <TinyEngine/Core/Assets/AssetTexture.hpp>

#include <TinyEngine/Core/FileSystem.hpp>

namespace TinyEngine
{
	void AssetTexture::OnAssetLoad()
	{
		const std::string path = FileSystem::GetInstance()->BuildPath(DirType::Assets, GetPath());

		_texture.loadFromFile(path);
		_texture.setRepeated(IsRepeated());
		_texture.setSmooth(IsSmooth());
		_texture.setSrgb(IsSrgb());
	}

	void AssetTexture::LoadTexture(Texture& texture)
	{
		texture.data = &_texture;
	}

	TINY_ENGINE_META_FACTORY_IMPL(AssetTexture)
}