#include "TextureAssets.hpp"

namespace TinyEngine
{
	void TextureAsset::LoadFromFile(const AssetParameters& params)
	{ 
		const auto& textureParams = static_cast<const TextureAssetParameters&>(params);

		_texture = std::make_unique<sf::Texture>();
		_texture->loadFromFile(textureParams.filePath);
	}

	void TextureAssets::OnAppEntry()
	{
		TextureAssetParameters params;

		params.filePath = "test.png";
		AddAsset("test", params);
	}

	void TextureAssets::OnAppQuit()
	{ 
		DestroyAssets();
	}
}
