#include "XmlArchive.hpp"

namespace TinyEngine
{
	bool XmlOutputArchive::ToSection(std::string_view id)
	{
		if (id.empty())
		{
			return true;
		}

		pugi::xml_node node;
		
		if (_data.poolSections.empty())
		{
			node = _data.document.append_child(id.data());
		}
		else
		{
			node = _data.poolSections.top().append_child(id.data());
		}
		
		_data.poolSections.push(node);

		return true;
	}

	bool XmlOutputArchive::HasSection(std::string_view id) const
	{
		return true;
	}

	void XmlOutputArchive::EndSection()
	{
		if (!_data.poolSections.empty())
		{
			_data.poolSections.pop();
		}
	}

	bool XmlOutputArchive::ToVariable(std::string_view id)
	{
		if (_data.poolSections.empty())
		{
			return false;
		}

		_data.lastAttribute = _data.poolSections.top().append_attribute(id.data());
		return _data.lastAttribute;
	}

	bool XmlOutputArchive::HasVariable(std::string_view id) const
	{
		if (_data.poolSections.empty())
		{
			return false;
		}

		return _data.poolSections.top().attribute(id.data());
	}

	void XmlOutputArchive::Save() const
	{
		const std::string path = GetPath();

		_data.document.save_file(path.c_str());
	}

	void XmlOutputArchive::SetBool(bool value)
	{
		if (!_data.lastAttribute)
		{
			return;
		}

		_data.lastAttribute.set_value(value);
	}

	void XmlOutputArchive::SetInt(int value)
	{
		if (!_data.lastAttribute)
		{
			return;
		}

		_data.lastAttribute.set_value(value);
	}

	void XmlOutputArchive::SetFloat(float value)
	{
		if (!_data.lastAttribute)
		{
			return;
		}

		_data.lastAttribute.set_value(value);
	}

	void XmlOutputArchive::SetString(std::string_view value)
	{
		if (!_data.lastAttribute)
		{
			return;
		}

		_data.lastAttribute.set_value(value.data());
	}

	bool XmlOutputArchive::ToItem(std::string_view id)
	{
		return ToSection(id);
	}

	void XmlOutputArchive::EndItem()
	{
		EndSection();
	}

	bool XmlOutputArchive::ToArray(std::string_view id)
	{
		return ToSection(id);
	}

	void XmlOutputArchive::EndArray()
	{
		EndSection();
	}

	bool XmlInputArchive::ToSection(std::string_view id)
	{
		if (id.empty())
		{
			return true;
		}

		pugi::xml_node node;

		if (_data.poolSections.empty())
		{
			node = _data.document.child(id.data());
		}
		else
		{
			node = _data.poolSections.top().child(id.data());
		}

		if (node)
		{
			_data.poolSections.push(node);
			return true;
		}

		return false;
	}

	bool XmlInputArchive::HasSection(std::string_view id) const
	{
		if (_data.poolSections.empty())
		{
			return false;
		}

		auto node = _data.poolSections.top().child(id.data());
		return node;
	}

	void XmlInputArchive::EndSection()
	{
		if (!_data.poolSections.empty())
		{
			_data.poolSections.pop();
		}
	}

	bool XmlInputArchive::ToVariable(std::string_view id)
	{
		if (!_data.poolSections.empty())
		{
			_data.lastAttribute = _data.poolSections.top().attribute(id.data());
		}
		
		return _data.lastAttribute;
	}

	bool XmlInputArchive::HasVariable(std::string_view id) const
	{
		if (_data.poolSections.empty())
		{
			return false;
		}

		auto attribute = _data.poolSections.top().attribute(id.data());
		return attribute;
	}

	void XmlInputArchive::Load()
	{
		const std::string path = GetPath();

		_data.document.load_file(path.c_str());
	}

	bool XmlInputArchive::GetBool() const
	{
		if (!_data.lastAttribute)
		{
			return false;
		}

		return _data.lastAttribute.as_bool();
	}

	int XmlInputArchive::GetInt() const
	{
		if (!_data.lastAttribute)
		{
			return 0;
		}

		return _data.lastAttribute.as_int();
	}

	float XmlInputArchive::GetFloat() const
	{
		if (!_data.lastAttribute)
		{
			return 0.f;
		}

		return _data.lastAttribute.as_float();
	}

	std::string XmlInputArchive::GetString() const
	{
		if (!_data.lastAttribute)
		{
			return "";
		}

		return _data.lastAttribute.as_string();
	}

	bool XmlInputArchive::ToItem(std::string_view id)
	{
		return ToSection(id);
	}

	void XmlInputArchive::EndItem()
	{
		EndSection();
	}

	bool XmlInputArchive::ToArray(std::string_view id)
	{
		return ToSection(id);
	}

	void XmlInputArchive::EndArray()
	{
		EndSection();
	}

	bool XmlInputArchive::ToNextItem(std::string_view id)
	{
		if (_data.poolSections.empty())
		{
			return false;
		}

		auto currNode = _data.poolSections.top();
		auto newNode = currNode.next_sibling(id.data());

		if (!newNode)
		{
			return false;
		}

		_data.poolSections.pop();
		_data.poolSections.push(newNode);

		return true;
	}
}
