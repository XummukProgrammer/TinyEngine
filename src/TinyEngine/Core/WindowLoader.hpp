#ifndef _WINDOW_LOADER_HEADER_
#define _WINDOW_LOADER_HEADER_

#include <TinyEngine/Core/ILoader.hpp>

#include <string>

namespace TinyEngine::Core
{
	struct WindowInfo;

	class WindowLoader final : public ILoader
	{
	public:
		WindowLoader(WindowInfo* windowInfo);
		~WindowLoader() = default;

	public:
		bool LoadFromFile(const std::string& filePath) override;
		bool LoadFromNode(const pugi::xml_node& node) override;

		std::string GetFilePath() const override;
		DirType GetDirType() const override;

	private:
		WindowInfo* _windowInfo = nullptr;
	};
}

#endif // _WINDOW_LOADER_HEADER_
