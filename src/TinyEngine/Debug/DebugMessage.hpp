#ifndef _TINY_ENGINE_DEBUG_MESSAGE_HEADER_
#define _TINY_ENGINE_DEBUG_MESSAGE_HEADER_

#include <string>

namespace TE
{

class CDebugMessage
{
public:
	enum class Type
	{
		Info,
		Error,
		Critical,
		Assert,
		Verify
	};
	
public:
	CDebugMessage(Type type, const std::string& message);
	~CDebugMessage() = default;

public:
	Type getType() const;
	const std::string& getMessage() const;

	static std::string typeToString(Type type);

public:
	Type _type;
	std::string _message;
};

}

#endif // _TINY_ENGINE_DEBUG_MESSAGE_HEADER_
