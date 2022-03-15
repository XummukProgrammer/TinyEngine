#include "TextureComponent.hpp"

namespace TinyEngine::Common
{
	void TextureComponent::SetTextureKey(std::string_view key)
	{ 
		_textureKey = key;
	}

	const std::string& TextureComponent::GetTextureKey() const
	{
		return _textureKey;
	}

	TextureComponent::TexturePtr TextureComponent::GetTexture() const
	{
		// TODO: Реализовать используя ассеты
		return nullptr;
	}
}
