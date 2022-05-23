#ifndef _TINY_ENGINE_LOG_HEADER_
#define _TINY_ENGINE_LOG_HEADER_

#include "DebugMessage.hpp"

#include <TinyEngine/Core/Paths.hpp>

#include <string>
#include <map>
#include <list>

namespace TE
{

class CLog final
{
public:
	CLog() = default;
	~CLog() = default;

public:
	void setFileName(CDebugMessage::Type type, const std::string& fileName);
	const std::string& getFileName(CDebugMessage::Type type) const;

	void addLogMessage(const CDebugMessage& debugMessage);
	void dumpLogMessages(const CPaths& paths, CDebugMessage::Type type) const;
	void dumpAllLogMessages(const CPaths& paths) const;

private:
	void printLogMessageToConsole(const CDebugMessage& debugMessage);

private:
	std::map<CDebugMessage::Type, std::string> _fileNames;
	std::map<CDebugMessage::Type, std::list<CDebugMessage>> _messages;
};

}

#endif // _TINY_ENGINE_LOG_HEADER_
