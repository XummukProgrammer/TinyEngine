#ifndef _TEXTURE_RESOURCE_HEADER_
#define _TEXTURE_RESOURCE_HEADER_

#include <TinyEngine/Core/Assets/Resources/Resource.hpp>
#include <TinyEngine/Core/Forwards.hpp>

#include "raylib.h"

#include <string>
#include <memory>

namespace TinyEngine
{
	class TextureResource final : public Resource
	{
		struct Info
		{
			Texture2D texture;

			Info(const Texture2D& texture)
				: texture(texture)
			{
			}
		};

	public:
		TextureResource() = default;
		~TextureResource() = default;

	public:
		void Unload() override;

	public:
		bool IsCreate() const;
		void LoadFromFile(std::string_view filePath);

		// Перед использованием необходима проверка IsCreate()
		Texture2D& GetTexture() { return _info->texture; }

	private:
		std::unique_ptr<Info> _info;
	};
}

#endif // _TEXTURE_RESOURCE_HEADER_
