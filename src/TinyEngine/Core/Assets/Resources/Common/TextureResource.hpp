#ifndef _TEXTURE_RESOURCE_HEADER_
#define _TEXTURE_RESOURCE_HEADER_

#include <TinyEngine/Core/Assets/Resources/Resource.hpp>

#include <SFML/Graphics.hpp>

#include <string>

namespace TinyEngine
{
	class TextureResource final : public Resource
	{
	public:
		TextureResource() = default;
		~TextureResource() = default;

	public:
		void LoadFromFile(std::string_view filePath);

		void SetRepeated(bool isRepeated);
		void SetSmooth(bool isSmooth);
		void SetSrgb(bool isSrgb);

		sf::Texture& GetTexture() { return _texture; }
		const sf::Texture& GetConstTexture() const { return _texture; }

	public:
		sf::Texture _texture;
	};
}

#endif // _TEXTURE_RESOURCE_HEADER_
