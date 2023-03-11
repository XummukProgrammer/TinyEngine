#include "XmlArchive.hpp"

namespace TinyEngine
{
	void XmlOutputArchive::Save()
	{
		_document.save_file(GetPath().c_str());
	}

	void XmlOutputArchive::WriteKey(std::string_view name)
	{
		if (_stack.empty())
		{
			_stack.push(_document.append_child(name.data()));
		}
		else
		{
			_stack.push(_stack.top().append_child(name.data()));
		}
	}

	void XmlOutputArchive::EndKey()
	{
		_stack.pop();
	}

	void XmlOutputArchive::WriteBool(std::string_view id, bool value)
	{
		_stack.top().append_attribute(id.data()).set_value(value);
	}

	void XmlOutputArchive::WriteInt(std::string_view id, int value)
	{
		_stack.top().append_attribute(id.data()).set_value(value);
	}

	void XmlOutputArchive::WriteFloat(std::string_view id, float value)
	{
		_stack.top().append_attribute(id.data()).set_value(value);
	}

	void XmlOutputArchive::WriteString(std::string_view id, std::string_view value)
	{
		_stack.top().append_attribute(id.data()).set_value(value.data());
	}

	void XmlInputArchive::Load()
	{
		_document.load_file(GetPath().c_str());
	}

	void XmlInputArchive::ReadKey(std::string_view name)
	{
		if (_stack.empty())
		{
			_stack.push(_document.child(name.data()));
		}
		else
		{
			_stack.push(_stack.top().child(name.data()));
		}
	}

	void XmlInputArchive::EndKey()
	{
		_stack.pop();
	}

	bool XmlInputArchive::ReadBool(std::string_view id) const
	{
		return _stack.top().attribute(id.data()).as_bool();
	}

	int XmlInputArchive::ReadInt(std::string_view id) const
	{
		return _stack.top().attribute(id.data()).as_int();
	}

	float XmlInputArchive::ReadFloat(std::string_view id) const
	{
		return _stack.top().attribute(id.data()).as_float();
	}

	std::string XmlInputArchive::ReadString(std::string_view id) const
	{
		return _stack.top().attribute(id.data()).as_string();
	}
}
