#ifndef _ASSET_LOADER_HEADER_
#define _ASSET_LOADER_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Assets/Asset.hpp>

namespace TinyEngine
{
	class AssetSource final : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(AssetSource)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_asset, "_asset", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		AssetSource() = default;
		~AssetSource() = default;

	public:
		AssetSharedPtr GetAsset() const { return _asset; }

	private:
		AssetSharedPtr _asset;
	};

	class AssetLoader final : public Asset
	{
		TINY_ENGINE_META_CLASS_DERIVED_BEGIN(AssetLoader, Asset)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_path, "_path", "");
		}
		TINY_ENGINE_META_CLASS_END

		TINY_ENGINE_FACTORY_MEMBER(AssetLoader)

	public:
		AssetLoader() = default;
		~AssetLoader() = default;

	public:
		const std::string& GetPath() const { return _path; }
		const AssetSource& GetSource() const { return _source; }

	public:
		void OnAssetLoad() override;

	private:
		void Create();

	private:
		std::string _path;
		AssetSource _source;
	};
}

#endif // _ASSET_LOADER_HEADER_
