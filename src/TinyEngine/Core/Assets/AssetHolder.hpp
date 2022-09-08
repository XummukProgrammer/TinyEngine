#ifndef _ASSET_HOLDER_HEADER_
#define _ASSET_HOLDER_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Assets/Asset.hpp>

#include <memory>

namespace TinyEngine
{
	class AssetHolder final : public Asset
	{
		TINY_ENGINE_META_CLASS_DERIVED_BEGIN(AssetHolder, Asset)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER(_assets, "_assets", "");
		}
		TINY_ENGINE_META_CLASS_END
			
	public:
		using AssetsData = std::vector<AssetSharedPtr>;

	public:
		AssetHolder() = default;
		~AssetHolder() = default;

	public:
		const AssetsData& GetAssets() const { return _assets; }

	public:
		void OnAssetLoad() override;

	private:
		AssetsData _assets;
	};
}

#endif // _ASSET_HOLDER_HEADER_
