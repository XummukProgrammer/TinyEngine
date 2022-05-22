#ifndef _TINY_ENGINE_LOG_HEADER_
#define _TINY_ENGINE_LOG_HEADER_

#include <TinyEngine/Core/Paths.hpp>

#include <string>
#include <map>
#include <list>

namespace TE
{

class CLog final
{
public:
	enum class Type
	{
		Info,
		Error,
		Critical
	};

public:
	CLog() = default;
	~CLog() = default;

public:
	void setFileName(Type type, const std::string& fileName);
	const std::string& getFileName(Type type) const;

	void addLogMessage(Type type, const std::string& message);
	void dumpLogMessages(const CPaths& paths, Type type) const;
	void dumpAllLogMessages(const CPaths& paths) const;

private:
	std::map<Type, std::string> _fileNames;
	std::map<Type, std::list<std::string>> _messages;
};

}

#endif // _TINY_ENGINE_LOG_HEADER_
