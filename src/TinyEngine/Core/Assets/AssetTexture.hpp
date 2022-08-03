#ifndef _ASSET_TEXTURE_HEADER_
#define _ASSET_TEXTURE_HEADER_

#include <TinyEngine/Core/Assets/Asset.hpp>
#include <TinyEngine/Render/Render.hpp>

#include <SFML/Graphics.hpp>

#include <string>

namespace TinyEngine
{
	class AssetTexture : public Asset
	{
		TINY_ENGINE_SER_BEGIN_DERIVED(AssetTexture, Asset)
		{
			TINY_ENGINE_SER_FIELD(_path)
			TINY_ENGINE_SER_FIELD(_isRepeated)
			TINY_ENGINE_SER_FIELD(_isSmooth)
			TINY_ENGINE_SER_FIELD(_isSrgb)
		}
		TINY_ENGINE_SER_END

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
		TINY_ENGINE_SER_BEGIN_DERIVED(AssetSfmlTexture, AssetTexture)
		{
		}
		TINY_ENGINE_SER_END

	public:
		AssetSfmlTexture() = default;
		~AssetSfmlTexture() = default;

	public:
		void OnLoad() override;

	public:
		void LoadTexture(Texture& texture) override;

	private:
		sf::Texture _texture;
	};
}

#endif // _ASSET_TEXTURE_HEADER_
