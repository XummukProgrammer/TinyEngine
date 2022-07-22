#ifndef _APPLICATION_HEADER_
#define _APPLICATION_HEADER_

#include <TinyEngine/Debug/Debug.hpp>
#include <TinyEngine/Logger/Logger.hpp>
#include <TinyEngine/Render/Render.hpp>

#include <TinyEngine/Render/SfmlRender.hpp>

namespace TinyEngine
{
	class Application final
	{
	public:
		Application() = default;
		~Application() = default;

	public:
		void SetExecutePath(std::string_view executePath);
		const std::string& GetExecutePath() const { return _executePath; }
		const std::string& GetExecuteDir() const { return _executeDir; }
		std::string GetRootDir() const { return _executeDir + "../"; }
		std::string GetAssetsDir() const { return GetRootDir() + "assets/"; }
		std::string GetLogsDir() const { return GetRootDir() + "_logs/"; }

		void Execute();
		void LoggerDumpToFile();

	public:
		Debug& GetDebug() { return debug; }
		Logger& GetLogger() { return logger; }
		Render& GetRender() { return render; }

	private:
		std::string _executePath;
		std::string _executeDir;
	};

	extern Application application;
}

#endif // _APPLICATION_HEADER_
