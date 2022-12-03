﻿#include "TextureAsset.hpp"

#include <TinyEngine/Core/Assets/Resources/Resources.hpp>
#include <TinyEngine/Core/Assets/Resources/Common/TextureResource.hpp>
#include <TinyEngine/Core/FileSystem.hpp>

namespace TinyEngine
{
	void TextureAsset::OnAssetLoad()
	{
		const auto filePath = FileSystem::GetInstance()->BuildPath(DirType::Project, _filePath);

		auto textureResource = std::make_shared<TextureResource>();
		textureResource->LoadFromFile(filePath);

		Resources::GetInstance()->AddResource(GetId(), textureResource);
	}
}
