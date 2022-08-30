#include "IntProperty.hpp"

#include <TinyEngine/Data/Serialization/SerializationDefines.hpp>

namespace TinyEngine
{
	IntPropertyWrapper::IntPropertyWrapper(std::string_view name, std::string_view description, int& value)
		: IProperty(name, description)
		, _value(value)
	{
	}

	void IntPropertyWrapper::LoadFromArchive(InputArchivePtr archive)
	{
		SerializationVisitor<int>::Load(archive, GetName(), &_value);
	}

	void IntPropertyWrapper::SaveToArchive(OutputArchivePtr archive)
	{
		SerializationVisitor<int>::Save(archive, GetName(), &_value);
	}

	void IntPropertyWrapper::GuiDraw(IRenderWindowSharedPtr window)
	{
	}

	IntProperty::IntProperty(std::string_view name, std::string_view description)
		: IntPropertyWrapper(name, description, _value)
	{
	}
}
