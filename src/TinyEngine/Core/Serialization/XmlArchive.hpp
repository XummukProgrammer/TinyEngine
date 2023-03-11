#ifndef _XML_ARCHIVE_HEADER_
#define _XML_ARCHIVE_HEADER_

#include <TinyEngine/Core/Serialization/IArchive.hpp>

#include <pugixml.hpp>

#include <stack>

namespace TinyEngine
{
	class XmlInputArchive final : public IInputArchive
	{
	public:
		XmlInputArchive() = default;
		~XmlInputArchive() = default;

		void Load() override;

		void ReadKey(std::string_view name) override;
		void EndKey() override;

		bool ReadBool(std::string_view id) const override;
		int ReadInt(std::string_view id) const override;
		float ReadFloat(std::string_view id) const override;
		std::string ReadString(std::string_view id) const override;

	private:
		pugi::xml_document _document;
		std::stack<pugi::xml_node> _stack;
	};

	class XmlOutputArchive final : public IOutputArchive
	{
	public:
		XmlOutputArchive() = default;
		~XmlOutputArchive() = default;

		void Save() override;

		void WriteKey(std::string_view name) override;
		void EndKey() override;

		void WriteBool(std::string_view id, bool value) override;
		void WriteInt(std::string_view id, int value) override;
		void WriteFloat(std::string_view id, float value) override;
		void WriteString(std::string_view id, std::string_view value) override;

	private:
		pugi::xml_document _document;
		std::stack<pugi::xml_node> _stack;
	};
}

#endif // _XML_ARCHIVE_HEADER_
