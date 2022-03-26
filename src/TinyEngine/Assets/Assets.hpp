#ifndef _ASSETS_HEADER_
#define _ASSETS_HEADER_

#include <TinyEngine/Assets/IAsset.hpp>
#include <TinyEngine/Assets/AssetParameters.hpp>

#include <map>
#include <string>
#include <memory>

namespace TinyEngine
{
	template<typename T, typename TParams>
	class Assets
	{
	public:
		Assets() = default;
		virtual ~Assets() = default;

	public:
		virtual void OnAppEntry() {}
		virtual void OnAppQuit() {}

	public:
		virtual void LoadFromFile(std::string_view filePath) = 0;

		void AddAsset(std::string_view key, const TParams& params);
		T* GetAsset(std::string_view key) const;
		bool HasAsset(std::string_view key) const;
		void DestroyAssets();

	private:
		std::map<std::string, std::unique_ptr<IAsset>> _assets;
	};

	template<typename T, typename TParams>
	void Assets<T, TParams>::AddAsset(std::string_view key, const TParams& params)
	{ 
		auto asset = std::make_unique<T>();
		asset->LoadFromFile(params);

		_assets[std::string{key}] = std::move(asset);
	}

	template<typename T, typename TParams>
	T* Assets<T, TParams>::GetAsset(std::string_view key) const
	{
		const auto it = _assets.find(std::string{key});

		if (it != _assets.end())
		{
			return dynamic_cast<T*>(it->second.get());
		}

		return nullptr;
	}

	template<typename T, typename TParams>
	bool Assets<T, TParams>::HasAsset(std::string_view key) const
	{
		return _assets.find(std::string{key}) != _assets.end();
	}

	template<typename T, typename TParams>
	void Assets<T, TParams>::DestroyAssets()
	{ 
		_assets.clear();
	}
}

#endif // _ASSETS_HEADER_
