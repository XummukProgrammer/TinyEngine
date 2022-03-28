#include "TextureAssets.hpp"

#include <TinyEngine/Core/Application.hpp>

#include <fmt/format.h>
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
		auto&& filePath = Application::GetInstance().GetConstPathBuilder().BuildPath(PathBuilder::DirType::Assets, "textures.xml");
		LoadFromFile(filePath);
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

		auto fileDir = Application::GetInstance().GetConstPathBuilder().FilePathToDir(filePath);
		auto rootNode = doc.child("root");

		for (auto textureNode = rootNode.first_child(); textureNode; textureNode = textureNode.next_sibling())
		{
			std::string key = textureNode.attribute("key").as_string();

			TextureAssetParameters params;
			params.filePath = fmt::format("{}{}", fileDir, textureNode.attribute("filePath").as_string());

			AddAsset(key, params);
		}
	}
}
