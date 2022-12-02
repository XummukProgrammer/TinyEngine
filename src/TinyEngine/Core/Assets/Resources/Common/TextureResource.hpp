#ifndef _TEXTURE_RESOURCE_HEADER_
#define _TEXTURE_RESOURCE_HEADER_

#include <TinyEngine/Core/Assets/Resources/Resource.hpp>

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

	public:
	};
}

#endif // _TEXTURE_RESOURCE_HEADER_
