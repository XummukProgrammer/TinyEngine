#ifndef _TINY_ENGINE_PATHS_HEADER_
#define _TINY_ENGINE_PATHS_HEADER_

#include <map>
#include <string>

namespace TE
{

class CPaths final
{
public:
	enum class Type
	{
		Exec,
		Logs,
		Configs
	};

public:
	CPaths(int argc, char* argv[]);
	~CPaths() = default;

public:
	void setPath(Type type, const std::string& path);
	const std::string& getPath(Type type) const;
	
	std::string buildPath(Type type, const std::string& path) const;

	void createPath(Type type);
	void checkAllPaths();

private:
	void setExecPath(int argc, char* argv[]);

private:
	std::map<Type, std::string> _paths;
};

}

#endif // _TINY_ENGINE_PATHS_HEADER_
