#ifndef _ASSET_TEXTURE_HEADER_
#define _ASSET_TEXTURE_HEADER_

#include <TinyEngine/Core/Assets/Asset.hpp>
#include <TinyEngine/Core/Render/Render.hpp>

#include <TinyEngine/Core/Render/Texture.hpp>

#ifdef TINY_ENGINE_USE_SFML
#include <SFML/Graphics.hpp>
#endif

#include <string>

namespace TinyEngine
{
	class AssetTexture : public Asset
	{
		TINY_ENGINE_META_CLASS_DERIVED_BEGIN(AssetTexture, Asset)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_path, "_path", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_isRepeated, "_isRepeated", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_isSmooth, "_isSmooth", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_isSrgb, "_isSrgb", "");
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
		void LoadTexture(Texture& texture);

		void OnAssetLoad() override;

	private:
		std::string _path;
		bool _isRepeated;
		bool _isSmooth;
		bool _isSrgb;

#ifdef TINY_ENGINE_USE_SFML
		sf::Texture _texture;
#endif
	};
}

#endif // _ASSET_TEXTURE_HEADER_
