#include "TextureAssets.hpp"

#include <pugixml.hpp>

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
		LoadFromFile("test.xml");
	}

	void TextureAssets::OnAppQuit()
	{
		DestroyAssets();
	}

	void TextureAssets::LoadFromFile(std::string_view filePath)
	{ 
		pugi::xml_document doc;
		
		if (!doc.load_file(filePath.data()))
		{
			return;
		}

		auto rootNode = doc.child("root");

		for (auto textureNode = rootNode.first_child(); textureNode; textureNode = textureNode.next_sibling())
		{
			std::string key = textureNode.attribute("key").as_string();

			TextureAssetParameters params;
			params.filePath = textureNode.attribute("filePath").as_string();

			AddAsset(key, params);
		}
	}
}
