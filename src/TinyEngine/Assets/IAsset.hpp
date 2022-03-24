#ifndef _INTERFACE_ASSET_HEADER_
#define _INTERFACE_ASSET_HEADER_

#include <TinyEngine/Assets/AssetParameters.hpp>

namespace TinyEngine
{
	class IAsset
	{
	public:
		IAsset() = default;
		virtual ~IAsset() = default;

	public:
		virtual void LoadFromFile(const AssetParameters& params) = 0;
	};
}

#endif // _INTERFACE_ASSET_HEADER_
