#ifndef _ASSET_HOLDER_HEADER_
#define _ASSET_HOLDER_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Assets/Asset.hpp>
#include <TinyEngine/Data/Serialization/SerializationVisitor.hpp>

#include <memory>

namespace TinyEngine
{
	class AssetHolder final : public Asset
	{
		TINY_ENGINE_SER_BEGIN_DERIVED(AssetHolder, Asset)
		{
			TINY_ENGINE_SER_FIELD(_assets)
		}
		TINY_ENGINE_SER_END
			
	public:
		using AssetsData = std::vector<AssetSharedPtr>;

	public:
		AssetHolder() = default;
		~AssetHolder() = default;

	public:
		const AssetsData& GetAssets() const { return _assets; }

	public:
		void OnLoad() override;

	private:
		AssetsData _assets;
	};
}

#endif // _ASSET_HOLDER_HEADER_
