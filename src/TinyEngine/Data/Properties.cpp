#include "Properties.hpp"

namespace TE
{

void CProperties::setIntProperty(const std::string& id, int value)
{ 
	setProperty(id, PropertyType::Int, value);
}

int CProperties::getIntProperty(const std::string& id, int defValue) const
{
	if (auto ptr = getProperty(id, PropertyType::Int)) {
		return std::any_cast<int>(ptr->value);
	}
	return defValue;
}

void CProperties::setFloatProperty(const std::string& id, float value)
{ 
	setProperty(id, PropertyType::Float, value);
}

float CProperties::getFloatProperty(const std::string & id, float defValue) const
{
	if (auto ptr = getProperty(id, PropertyType::Float)) {
		return std::any_cast<float>(ptr->value);
	}
	return defValue;
}

void CProperties::setStringProperty(const std::string& id, const std::string& value)
{ 
	setProperty(id, PropertyType::String, value);
}

std::string CProperties::getStringProperty(const std::string & id, const std::string & defValue) const
{
	if (auto ptr = getProperty(id, PropertyType::String)) {
		return std::any_cast<std::string>(ptr->value);
	}
	return defValue;
}

void CProperties::createProperties(const std::string& id)
{ 
	setProperty(id, PropertyType::Properties, new CProperties);
}

CProperties* CProperties::getProperties(const std::string& id) const
{
	if (auto ptr = getProperty(id, PropertyType::Properties)) {
		return std::any_cast<CProperties*>(ptr->value);
	}
	return nullptr;
}

bool CProperties::hasProperty(const std::string& id) const
{
	return _propertiesMap.find(id) != _propertiesMap.end();
}

bool CProperties::isIntProperty(const std::string& id) const
{
	return getProperty(id, PropertyType::Int) != nullptr;
}

bool CProperties::isFloatProperty(const std::string& id) const
{
	return getProperty(id, PropertyType::Float) != nullptr;
}

bool CProperties::isStringProperty(const std::string& id) const
{
	return getProperty(id, PropertyType::String) != nullptr;
}

void CProperties::setProperty(const std::string& id, PropertyType type, std::any value)
{ 
	auto it = _propertiesMap.find(id);
	if (it == _propertiesMap.end()) {
		auto newPtr = std::make_unique<CPropertyDataPtr::element_type>();
		newPtr->type = type;
		newPtr->value = value;
		_propertiesMap.emplace(id, std::move(newPtr));

	} else {
		auto& ptr = it->second;
		ptr->type = type;
		ptr->value = value;
	}
}

CProperties::CPropertyData* CProperties::getProperty(const std::string& id, PropertyType type) const
{
	auto it = _propertiesMap.find(id);
	if (it != _propertiesMap.end()) {
		if (const auto& ptr = it->second) {
			if (ptr->type == type) {
				return ptr.get();
			}
		}
	}
	return nullptr;
}

bool CProperties::removeProperty(const std::string& id)
{ 
	auto it = _propertiesMap.find(id);
	if (it != _propertiesMap.end()) {
		auto& ptr = it->second;
		if (ptr->type == PropertyType::Properties) {
			auto* propertiesValue = std::any_cast<CProperties*>(ptr->value);
			delete propertiesValue;
		}
		_propertiesMap.erase(it);
		return true;
	}
	return false;
}

}
