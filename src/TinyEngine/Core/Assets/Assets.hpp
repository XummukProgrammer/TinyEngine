#ifndef _ASSETS_HEADER_
#define _ASSETS_HEADER_

#include <TinyEngine/Data/Singleton.hpp>

#include <TinyEngine/Core/Assets/AssetHolder.hpp>

namespace TinyEngine
{
	class Assets final : public Singleton<Assets>
	{
	public:
		Assets() = default;
		~Assets() = default;

	public:
		void LoadFromFile();

		AssetHolder& GetAssetHolder() { return _holder; }
		const AssetHolder& GetConstAssetHolder() const { return _holder; }

	private:
		AssetHolder _holder;
	};
}

#endif // _ASSETS_HEADER_
