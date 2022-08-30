#include "MetaIntMember.hpp"

#include <TinyEngine/Data/Serialization/SerializationDefines.hpp>

namespace TinyEngine
{
	MetaIntMemberWrapper::MetaIntMemberWrapper(std::string_view name, std::string_view description, int& value)
		: IMetaMember(name, description)
		, _value(value)
	{
	}

	void MetaIntMemberWrapper::LoadFromArchive(InputArchivePtr archive)
	{
		SerializationVisitor<int>::Load(archive, GetName(), &_value);
	}

	void MetaIntMemberWrapper::SaveToArchive(OutputArchivePtr archive)
	{
		SerializationVisitor<int>::Save(archive, GetName(), &_value);
	}

	void MetaIntMemberWrapper::GuiDraw(IRenderWindowSharedPtr window)
	{
	}

	MetaIntMember::MetaIntMember(std::string_view name, std::string_view description)
		: MetaIntMemberWrapper(name, description, _value)
	{
	}
}
