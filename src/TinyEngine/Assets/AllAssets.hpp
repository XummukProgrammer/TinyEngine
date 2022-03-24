#ifndef _ALL_ASSETS_HEADER_
#define _ALL_ASSETS_HEADER_

#include <TinyEngine/Assets/TextureAssets.hpp>

#include <SFML/Graphics.hpp>

namespace TinyEngine
{
	class AllAssets final
	{
	public:
		AllAssets() = default;
		~AllAssets() = default;

	public:
		void OnAppEntry();
		void OnAppQuit();

	public:
		TextureAssets& GetTextureAssets() { return _textureAssets; }
		const TextureAssets& GetConstTextureAssets() const { return _textureAssets; }

	public:
		TextureAssets _textureAssets;
	};
}

#endif // _ALL_ASSETS_HEADER_
