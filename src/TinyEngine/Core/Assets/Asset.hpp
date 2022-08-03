#ifndef _ASSET_HEADER_
#define _ASSET_HEADER_

#include <TinyEngine/Data/Serialization/SerializationVisitor.hpp>

#include <memory>

namespace TinyEngine
{
	class Asset : public ISerializable
	{
		TINY_ENGINE_SER_BEGIN(Asset)
		{
			TINY_ENGINE_SER_FIELD(_id)
		}
		TINY_ENGINE_SER_END

	public:
		using Ptr = std::shared_ptr<Asset>;

	public:
		Asset() = default;
		virtual ~Asset() = default;

	public:
		const std::string& GetId() const;

	public:
		virtual void OnLoad() {}

	private:
		std::string _id;
	};
}

#endif // _ASSET_HEADER_
