#include "TextureAsset.hpp"

#include <SFML/Graphics.hpp>

namespace TinyEngine
{
	void TextureAsset::OnAssetLoad()
	{
		sf::Texture texture;
		texture.loadFromFile(_filePath);
	}
}
