#ifndef _PROPERTIES_HEADER_
#define _PROPERTIES_HEADER_

#include <string>
#include <map>
#include <memory>

namespace TinyEngine::Properties
{
	namespace Data
	{
		class BoolProperty;
		class IntProperty;
		class FloatProperty;
		class StringProperty;
	}

	class IProperty;

	class PropertiesData
	{
	public:
		using IPropertyPtr = std::shared_ptr<IProperty>;
		using BoolPropertyPtr = std::shared_ptr<Data::BoolProperty>;
		using IntPropertyPtr = std::shared_ptr<Data::IntProperty>;
		using FloatPropertyPtr = std::shared_ptr<Data::FloatProperty>;
		using StringPropertyPtr = std::shared_ptr<Data::StringProperty>;

	public:
		PropertiesData() = default;
		virtual ~PropertiesData() = default;

	public:
		void SetBoolProperty(std::string_view key, bool value);
		bool GetBoolProperty(std::string_view key, bool default) const;

		void SetIntProperty(std::string_view key, int value);
		int GetIntProperty(std::string_view key, int default) const;

		void SetFloatProperty(std::string_view key, float value);
		float GetFloatProperty(std::string_view key, float default) const;

		void SetStringProperty(std::string_view key, std::string_view value);
		std::string GetStringProperty(std::string_view key, const std::string& default) const;

		std::map<std::string, std::string> GetAllPropertiesStringValue() const;
		void DebugPrintAllProperties();

	protected:
		void SetProperty(std::string_view key, IPropertyPtr&& property);
		IPropertyPtr GetProperty(std::string_view key) const;

		BoolPropertyPtr GetBoolProperty(std::string_view key) const;
		IntPropertyPtr GetIntProperty(std::string_view key) const;
		FloatPropertyPtr GetFloatProperty(std::string_view key) const;
		StringPropertyPtr GetStringProperty(std::string_view key) const;

		const std::map<std::string, IPropertyPtr>& GetData() const;

	private:
		std::map<std::string, IPropertyPtr> _properties;
	};

	/// ~~~~~~~~~~~~~~~~~
	class XmlPropertiesData final : public PropertiesData
	{
	public:
		XmlPropertiesData() = default;
		~XmlPropertiesData() = default;

	public:
		void SaveToFile(const std::string& filePath);
		void LoadFromFile(const std::string& filePath);
	};
}

#endif // _PROPERTIES_HEADER_
