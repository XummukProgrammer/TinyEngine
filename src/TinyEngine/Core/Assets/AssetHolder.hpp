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
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_assets, "_assets", "");
		}
		TINY_ENGINE_META_CLASS_END
			
	public:
		using AssetsData = std::vector<AssetSharedPtr>;

	public:
		AssetHolder() = default;
		~AssetHolder() = default;

	public:
		const AssetsData& GetAssets() const { return _assets; }

		template<typename T>
		T* GetAsset(std::string_view id);

	public:
		void OnAssetLoad() override;

	private:
		AssetsData _assets;
	};

	template<typename T>
	T* AssetHolder::GetAsset(std::string_view id)
	{
		for (const auto& asset : _assets)
		{
			if (asset->GetId() == id)
			{
				return dynamic_cast<T*>(asset.get());
			}
		}

		return nullptr;
	}
}

#endif // _ASSET_HOLDER_HEADER_
