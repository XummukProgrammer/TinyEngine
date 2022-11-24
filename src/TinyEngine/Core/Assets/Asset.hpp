#ifndef _ASSET_HEADER_
#define _ASSET_HEADER_

#include <TinyEngine/Core/Data/Meta/MetaDefines.hpp>

namespace TinyEngine
{
	class Asset : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(Asset)
		{
		}
		TINY_ENGINE_META_CLASS_END

	public:
		Asset() = default;
		virtual ~Asset() = default;

	public:
		virtual void OnAssetLoad() {}
	};
}

#endif // _ASSET_HEADER_
