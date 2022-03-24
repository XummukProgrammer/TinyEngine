#ifndef _TEXTURE_ASSETS_HEADER_
#define _TEXTURE_ASSETS_HEADER_

#include <TinyEngine/Assets/AssetParameters.hpp>
#include <TinyEngine/Assets/IAsset.hpp>
#include <TinyEngine/Assets/Assets.hpp>

#include <SFML/Graphics.hpp>

#include <string>
#include <memory>

namespace TinyEngine
{
	class TextureAssetParameters final : public AssetParameters
	{
	public:
		TextureAssetParameters() = default;
		~TextureAssetParameters() = default;

	public:
		std::string filePath;
	};

	class TextureAsset final : public IAsset
	{
	public:
		TextureAsset() = default;
		~TextureAsset() = default;

	public:
		void LoadFromFile(const AssetParameters& params) override;

		sf::Texture& GetTexture() { return *_texture.get(); }
		const sf::Texture& GetConstTexture() const { return *_texture.get(); }

	private:
		std::unique_ptr<sf::Texture> _texture;
	};

	class TextureAssets final : public Assets<TextureAsset, TextureAssetParameters>
	{
	public:
		TextureAssets() = default;
		~TextureAssets() = default;

	public:
		void OnAppEntry() override;
		void OnAppQuit() override;
	};
}

#endif // _TEXTURE_ASSETS_HEADER_
