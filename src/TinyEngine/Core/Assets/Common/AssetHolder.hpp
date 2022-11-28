#ifndef _ASSET_HOLDER_HEADER_
#define _ASSET_HOLDER_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Assets/Asset.hpp>

#include <vector>

namespace TinyEngine
{
	class AssetHolder final : public Asset
	{
		TINY_ENGINE_META_CLASS_DERIVED_BEGIN(AssetHolder, Asset)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_assets, "Assets", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		AssetHolder() = default;
		~AssetHolder() = default;

	public:
		void OnAssetLoad() override;

	private:
		std::vector<AssetSharedPtr> _assets;
	};
}

#endif // _ASSET_HOLDER_HEADER_
