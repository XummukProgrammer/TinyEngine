#include "Paths.hpp"

#include <filesystem>

namespace TE
{

CPaths::CPaths(int argc, char* argv[])
{ 
	setExecPath(argc, argv);
}

void CPaths::setPath(Type type, const std::string& path)
{ 
	if (type == Type::Exec) {
		return;
	}

	_paths[type] = buildPath(Type::Exec, path);
}

const std::string& CPaths::getPath(Type type) const
{
	return _paths.at(type);
}

std::string CPaths::buildPath(Type type, const std::string& path) const
{
	return getPath(type) + path;
}

void CPaths::createPath(Type type)
{ 
	const auto& path = getPath(type);

	if (!std::filesystem::exists(path)) {
		std::filesystem::create_directories(path);
	}
}

void CPaths::checkAllPaths()
{ 
	createPath(Type::Logs);
}

void CPaths::setExecPath(int argc, char* argv[])
{
	_paths[Type::Exec] = std::filesystem::path(argv[0]).remove_filename().generic_string();
}

}
