#ifndef _LINK_ASSET_HEADER_
#define _LINK_ASSET_HEADER_

#include <TinyEngine/Core/Assets/Asset.hpp>

#include <string>

namespace TinyEngine
{
	class LinkAsset final : public Asset
	{
		TINY_ENGINE_META_CLASS_DERIVED_BEGIN(LinkAsset, Asset)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_filePath, "FilePath", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_type, "Type", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		LinkAsset() = default;
		~LinkAsset() = default;

	public:
		void OnAssetLoad() override;

	public:
		template<typename T> std::shared_ptr<T> GetAsset() const;

	private:
		std::string _filePath;
		std::string _type;
		AssetSharedPtr _asset;
	};

	template<typename T>
	std::shared_ptr<T> LinkAsset::GetAsset() const
	{
		if (_asset)
		{
			return std::dynamic_pointer_cast<T>(_asset);
		}
		return nullptr;
	}
}

#endif // _LINK_ASSET_HEADER_
