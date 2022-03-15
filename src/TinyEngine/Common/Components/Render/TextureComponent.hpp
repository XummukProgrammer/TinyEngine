#ifndef _TEXTURE_COMPONENT_HEADER_
#define _TEXTURE_COMPONENT_HEADER_

#include <TinyEngine/Level/Component.hpp>

#include <SFML/Graphics/Texture.hpp>

#include <string>
#include <memory>

namespace TinyEngine::Common
{
	class TextureComponent final : public Level::Component
	{
	public:
		using TexturePtr = std::shared_ptr<sf::Texture>;

	public:
		TextureComponent() = default;
		~TextureComponent() = default;

	public:
		void SetTextureKey(std::string_view key);
		const std::string& GetTextureKey() const;

		TexturePtr GetTexture() const;

	private:
		std::string _textureKey;
	};
}

#endif // _TEXTURE_COMPONENT_HEADER_
