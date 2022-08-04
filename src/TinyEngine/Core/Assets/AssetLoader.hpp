#ifndef _ASSET_LOADER_HEADER_
#define _ASSET_LOADER_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Assets/Asset.hpp>

namespace TinyEngine
{
	class AssetSource final : public ISerializable
	{
		TINY_ENGINE_SER_BEGIN(AssetSource)
		{
			TINY_ENGINE_SER_FIELD(_asset)
		}
		TINY_ENGINE_SER_END

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
		TINY_ENGINE_SER_BEGIN_DERIVED(AssetLoader, Asset)
		{
			TINY_ENGINE_SER_FIELD(_path)
		}
		TINY_ENGINE_SER_END

	public:
		AssetLoader() = default;
		~AssetLoader() = default;

	public:
		const std::string& GetPath() const { return _path; }
		const AssetSource& GetSource() const { return _source; }

	public:
		void OnLoad() override;

	private:
		void Create();

	private:
		std::string _path;
		AssetSource _source;
	};
}

#endif // _ASSET_LOADER_HEADER_
