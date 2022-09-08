#ifndef _ASSET_TEXTURE_HEADER_
#define _ASSET_TEXTURE_HEADER_

#include <TinyEngine/Core/Assets/Asset.hpp>
#include <TinyEngine/Render/Render.hpp>

#include <TinyEngine/Render/Texture.hpp>

#include <SFML/Graphics.hpp>

#include <string>

namespace TinyEngine
{
	class AssetTexture : public Asset
	{
		TINY_ENGINE_META_CLASS_DERIVED_BEGIN(AssetTexture, Asset)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER(_path, "_path", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER(_isRepeated, "_isRepeated", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER(_isSmooth, "_isSmooth", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER(_isSrgb, "_isSrgb", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		AssetTexture() = default;
		virtual ~AssetTexture() = default;

	public:
		const std::string& GetPath() const { return _path; }
		bool IsRepeated() const { return _isRepeated; }
		bool IsSmooth() const { return _isSmooth; }
		bool IsSrgb() const { return _isSrgb; }

	public:
		virtual void LoadTexture(Texture& texture) = 0;

	private:
		std::string _path;
		bool _isRepeated;
		bool _isSmooth;
		bool _isSrgb;
	};

	class AssetSfmlTexture final : public AssetTexture
	{
		TINY_ENGINE_META_CLASS_DERIVED_BEGIN(AssetSfmlTexture, AssetTexture)
		{
		}
		TINY_ENGINE_META_CLASS_END

	public:
		AssetSfmlTexture() = default;
		~AssetSfmlTexture() = default;

	public:
		void OnAssetLoad() override;

	public:
		void LoadTexture(Texture& texture) override;

		sf::Texture& GetTexture() { return _texture; }
		const sf::Texture& GetConstTexture() const { return _texture; }

	private:
		sf::Texture _texture;
	};
}

#endif // _ASSET_TEXTURE_HEADER_
