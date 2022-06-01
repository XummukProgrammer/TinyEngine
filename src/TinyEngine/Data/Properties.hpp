#ifndef _TINY_ENGINE_PROPERTIES_HEADER_
#define _TINY_ENGINE_PROPERTIES_HEADER_

#include <any>
#include <string>
#include <map>
#include <memory>

namespace TE
{

class CProperties final
{
private:
	enum class PropertyType
	{
		Int,
		Float,
		String,
		Properties
	};
	
	struct CPropertyData
	{
		PropertyType type;
		std::any value;
	};

public:
	using CPropertyDataPtr = std::unique_ptr<CPropertyData>;
	using CPropertiesMap = std::map<std::string, CPropertyDataPtr>;

public:
	CProperties() = default;
	~CProperties() = default;

public:
	void setIntProperty(const std::string& id, int value);
	int getIntProperty(const std::string& id, int defValue = 0) const;

	void setFloatProperty(const std::string& id, float value);
	float getFloatProperty(const std::string& id, float defValue = 0.f) const;

	void setStringProperty(const std::string& id, const std::string& value);
	std::string getStringProperty(const std::string& id, const std::string& defValue = "") const;

	void createProperties(const std::string& id);
	CProperties* getProperties(const std::string& id) const;

	bool hasProperty(const std::string& id) const;

	bool isIntProperty(const std::string& id) const;
	bool isFloatProperty(const std::string& id) const;
	bool isStringProperty(const std::string& id) const;

	bool removeProperty(const std::string& id);

private:
	void setProperty(const std::string& id, PropertyType type, std::any value);
	CPropertyData* getProperty(const std::string& id, PropertyType type) const;

private:
	CPropertiesMap _propertiesMap;
};

}

#endif // _TINY_ENGINE_PROPERTIES_HEADER_
