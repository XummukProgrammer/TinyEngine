#ifndef _XML_ARCHIVE_HEADER_
#define _XML_ARCHIVE_HEADER_

#include <TinyEngine/Core/Data/Serialization/Serialization.hpp>

#include <pugixml.hpp>

#include <stack>
#include <vector>

namespace TinyEngine
{
	struct XmlDataArchive
	{
		pugi::xml_document document;
		std::stack<pugi::xml_node> poolSections;
		pugi::xml_attribute lastAttribute;
	};

	class XmlOutputArchive final : public OutputArchive
	{
	public:
		XmlOutputArchive() = default;
		~XmlOutputArchive() = default;

	public:
		bool ToSection(std::string_view id) override;
		bool HasSection(std::string_view id) const override;
		void EndSection() override;

		bool ToVariable(std::string_view id) override;
		bool HasVariable(std::string_view id) const override;

		void Save() const override;

		void SetBool(bool value) override;
		void SetInt(int value) override;
		void SetFloat(float value) override;
		void SetString(std::string_view value) override;

		bool ToItem(std::string_view id) override;
		void EndItem() override;

		bool ToArray(std::string_view id) override;
		void EndArray() override;

	private:
		XmlDataArchive _data;
	};

	class XmlInputArchive final : public InputArchive
	{
	public:
		XmlInputArchive() = default;
		~XmlInputArchive() = default;

	public:
		bool ToSection(std::string_view id) override;
		bool HasSection(std::string_view id) const override;
		void EndSection() override;

		bool ToVariable(std::string_view id) override;
		bool HasVariable(std::string_view id) const override;

		void Load() override;

		bool GetBool() const override;
		int GetInt() const override;
		float GetFloat() const override;
		std::string GetString() const override;

		bool ToItem(std::string_view id) override;
		void EndItem() override;

		bool ToArray(std::string_view id) override;
		void EndArray() override;

		bool ToNextItem(std::string_view id) override;

	private:
		XmlDataArchive _data;
	};
}

#endif // _XML_ARCHIVE_HEADER_
