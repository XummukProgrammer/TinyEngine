#include "Properties.hpp"

#include <TinyEngine/Properties/Data/BoolProperty.hpp>
#include <TinyEngine/Properties/Data/IntProperty.hpp>
#include <TinyEngine/Properties/Data/FloatProperty.hpp>
#include <TinyEngine/Properties/Data/StringProperty.hpp>

#include <TinyEngine/Core/Context.hpp>
#include <TinyEngine/Core/FileSystem.hpp>
#include <TinyEngine/Core/Factory.hpp>

#include <fmt/format.h>
#include <pugixml.hpp>

namespace TinyEngine::Properties
{
	static inline const Core::DirType DIR_TYPE = Core::DirType::Data;

	void Properties::SetProperty(std::string_view key, IPropertyPtr&& property)
	{ 
		_properties[std::string{key}] = std::move(property);
	}

	Properties::IPropertyPtr Properties::GetProperty(std::string_view key) const
	{
		auto it = _properties.find(std::string{key});

		if (it != _properties.end())
		{
			return it->second;
		}

		return nullptr;
	}

	/// ~~~~~~~~~~~~~~~~~
	void Properties::SetBoolProperty(std::string_view key, bool value)
	{ 
		if (auto property = GetBoolProperty(key))
		{
			property->SetValue(value);
			return;
		}

		auto property = std::make_shared<Data::BoolProperty>();
		property->SetValue(value);
		SetProperty(key, std::move(property));
	}

	bool Properties::GetBoolProperty(std::string_view key, bool default) const
	{
		if (auto property = GetBoolProperty(key))
		{
			return property->GetValue();
		}

		return default;
	}

	Properties::BoolPropertyPtr Properties::GetBoolProperty(std::string_view key) const
	{
		if (auto property = GetProperty(key))
		{
			return std::dynamic_pointer_cast<Data::BoolProperty>(property);
		}

		return nullptr;
	}

	/// ~~~~~~~~~~~~~~~~~
	void Properties::SetIntProperty(std::string_view key, int value)
	{ 
		if (auto property = GetIntProperty(key))
		{
			property->SetValue(value);
			return;
		}

		auto property = std::make_shared<Data::IntProperty>();
		property->SetValue(value);
		SetProperty(key, std::move(property));
	}

	Properties::IntPropertyPtr Properties::GetIntProperty(std::string_view key) const
	{
		if (auto property = GetProperty(key))
		{
			return std::dynamic_pointer_cast<Data::IntProperty>(property);
		}

		return nullptr;
	}

	int Properties::GetIntProperty(std::string_view key, int default) const
	{
		if (auto property = GetIntProperty(key))
		{
			return property->GetValue();
		}

		return default;
	}

	/// ~~~~~~~~~~~~~~~~~
	void Properties::SetFloatProperty(std::string_view key, float value)
	{ 
		if (auto property = GetFloatProperty(key))
		{
			property->SetValue(value);
			return;
		}

		auto property = std::make_shared<Data::FloatProperty>();
		property->SetValue(value);
		SetProperty(key, std::move(property));
	}

	float Properties::GetFloatProperty(std::string_view key, float default) const
	{
		if (auto property = GetFloatProperty(key))
		{
			return property->GetValue();
		}

		return default;
	}

	Properties::FloatPropertyPtr Properties::GetFloatProperty(std::string_view key) const
	{
		if (auto property = GetProperty(key))
		{
			return std::dynamic_pointer_cast<Data::FloatProperty>(property);
		}

		return nullptr;
	}

	/// ~~~~~~~~~~~~~~~~~
	void Properties::SetStringProperty(std::string_view key, std::string_view value)
	{ 
		if (auto property = GetStringProperty(key))
		{
			property->SetValue(value);
			return;
		}

		auto property = std::make_shared<Data::StringProperty>();
		property->SetValue(value);
		SetProperty(key, std::move(property));
	}

	std::string Properties::GetStringProperty(std::string_view key, const std::string& default) const
	{
		if (auto property = GetStringProperty(key))
		{
			return property->GetValue();
		}

		return default;
	}

	Properties::StringPropertyPtr Properties::GetStringProperty(std::string_view key) const
	{
		if (auto property = GetProperty(key))
		{
			return std::dynamic_pointer_cast<Data::StringProperty>(property);
		}

		return nullptr;
	}

	const std::map<std::string, Properties::IPropertyPtr>& Properties::GetData() const
	{
		return _properties;
	}

	/// ~~~~~~~~~~~~~~~~~
	std::map<std::string, std::string> Properties::GetAllPropertiesStringValue() const
	{
		std::map<std::string, std::string> properties;

		for (const auto& [ key, value ] : _properties)
		{
			properties[key] = value->ToString();
		}

		return properties;
	}

	void Properties::DebugPrintAllProperties()
	{ 
		std::string printString;
		auto&& properties = GetAllPropertiesStringValue();

		for (const auto& [ key, value ] : properties)
		{
			printString += fmt::format("Key: {} | Value: {}\n", key, value);
		}

		fmt::print(printString);
	}

	/// ~~~~~~~~~~~~~~~~~
	void XmlProperties::SaveToFile(const std::shared_ptr<Core::Context>& context, const std::string& filePath)
	{ 
		pugi::xml_document doc;
		auto&& rootNode = doc.append_child("root");

		for (const auto& [ key, property ] : GetData())
		{
			auto&& propertyNode = rootNode.append_child(key.c_str());
			auto&& propertyTypeAttr = propertyNode.append_attribute("type");
			propertyTypeAttr.set_value(property->GetClassName().c_str());
			property->SaveToFile(propertyNode);
		}

		auto&& path = context->BuildPath(DIR_TYPE, filePath);
		doc.save_file(path.c_str());
	}

	void XmlProperties::LoadFromFile(const std::shared_ptr<Core::Context>& context, const std::string& filePath)
	{
		auto&& path = context->BuildPath(DIR_TYPE, filePath);

		pugi::xml_document doc;
		doc.load_file(path.c_str());

		auto&& rootNode = doc.child("root");

		for (auto&& propertyNode = rootNode.first_child(); propertyNode; propertyNode = propertyNode.next_sibling())
		{
			auto&& propertyTypeAttr = propertyNode.attribute("type");
			auto&& propertyType = std::string{propertyTypeAttr.value()};

			if (auto property = Core::Factory::GetInstance().Create<IProperty>(propertyType))
			{
				property->LoadFromFile(propertyNode);

				auto&& propertyKey = std::string{propertyNode.name()};
				SetProperty(propertyKey, std::move(property));
			}
		}
	}
}
