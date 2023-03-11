#ifndef _I_ARCHIVE_HEADER_
#define _I_ARCHIVE_HEADER_

#include <string>

namespace TinyEngine
{
	class Archive
	{
	public:
		Archive() = default;
		virtual ~Archive() = default;

		void SetPath(std::wstring_view path) { _path = path; }
		const std::wstring& GetPath() const { return _path; }

	private:
		std::wstring _path;
	};

	class IInputArchive : public Archive
	{
	public:
		IInputArchive() = default;
		virtual ~IInputArchive() = default;

		virtual void Load() = 0;

		virtual void ReadKey(std::string_view name) = 0;
		virtual void EndKey() = 0;

		virtual bool ReadBool(std::string_view id) const = 0;
		virtual int ReadInt(std::string_view id) const = 0;
		virtual float ReadFloat(std::string_view id) const = 0;
		virtual std::string ReadString(std::string_view id) const = 0;
	};

	class IOutputArchive : public Archive
	{
	public:
		IOutputArchive() = default;
		virtual ~IOutputArchive() = default;

		virtual void Save() = 0;

		virtual void WriteKey(std::string_view name) = 0;
		virtual void EndKey() = 0;

		virtual void WriteBool(std::string_view id, bool value) = 0;
		virtual void WriteInt(std::string_view id, int value) = 0;
		virtual void WriteFloat(std::string_view id, float value) = 0;
		virtual void WriteString(std::string_view id, std::string_view value) = 0;
	};
}

#endif // _I_ARCHIVE_HEADER_
