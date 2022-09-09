#ifndef _ASSET_HEADER_
#define _ASSET_HEADER_

#include <TinyEngine/Data/Serialization/SerializationDefines.hpp>
#include <TinyEngine/Data/Meta/MetaDefines.hpp>

#include <memory>

namespace TinyEngine
{
	class Asset : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(Asset)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_id, "_id", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		Asset() = default;
		virtual ~Asset() = default;

	public:
		const std::string& GetId() const;

	public:
		virtual void OnAssetLoad() {}

	private:
		std::string _id;
	};
}

#endif // _ASSET_HEADER_
