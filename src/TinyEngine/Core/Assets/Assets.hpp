#ifndef _ASSETS_HEADER_
#define _ASSETS_HEADER_

#include <TinyEngine/Data/Singleton.hpp>

#include <TinyEngine/Core/Assets/AssetHolder.hpp>

namespace TinyEngine
{
	class Assets final : public Singleton<Assets>
	{
	public:
		using AssetPtr = std::shared_ptr<Asset>;

	public:
		Assets() = default;
		~Assets() = default;

	public:
		void LoadFromFile();

	private:
		AssetHolder _holder;
	};
}

#endif // _ASSETS_HEADER_
