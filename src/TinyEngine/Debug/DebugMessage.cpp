#include "DebugMessage.hpp"

#include <map>

namespace TE
{

CDebugMessage::CDebugMessage(Type type, const std::string& message)
	: _type(type)
	, _message(message)
{}

CDebugMessage::Type CDebugMessage::getType() const
{
	return _type;
}

const std::string& CDebugMessage::getMessage() const
{
	return _message;
}

std::string CDebugMessage::typeToString(Type type)
{
	static std::map<Type, std::string> table;
	if (table.empty()) {
		table[Type::Info] = "Info";
		table[Type::Error] = "Error";
		table[Type::Critical] = "Critical";
	}

	auto it = table.find(type);
	if (it != table.end()) {
		return it->second;
	}
	return "";
}

}
