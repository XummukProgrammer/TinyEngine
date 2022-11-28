#ifndef _ASSET_HEADER_
#define _ASSET_HEADER_

#include <TinyEngine/Core/Data/Meta/MetaDefines.hpp>

#include <string>

namespace TinyEngine
{
	class Asset : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(Asset)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_id, "ID", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		Asset() = default;
		virtual ~Asset() = default;

	public:
		virtual void OnAssetLoad() {}

	public:
		const std::string& GetId() const { return _id; }

		void SetFilePath(std::string_view filePath) { _filePath = filePath; }
		const std::string& GetFilePath() const { return _filePath; }

	private:
		std::string _id;
		std::string _filePath;
	};
}

#endif // _ASSET_HEADER_
