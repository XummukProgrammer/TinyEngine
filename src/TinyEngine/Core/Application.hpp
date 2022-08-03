#ifndef _APPLICATION_HEADER_
#define _APPLICATION_HEADER_

#include <TinyEngine/Core/Debug/Debug.hpp>
#include <TinyEngine/Core/Logger/Logger.hpp>
#include <TinyEngine/Render/Render.hpp>
#include <TinyEngine/Gui/Gui.hpp>
#include <TinyEngine/Data/Factory/Factory.hpp>
#include <TinyEngine/Core/Assets/Assets.hpp>

#include <TinyEngine/Render/SfmlRender.hpp>

namespace TinyEngine
{
	class Application final : public Singleton<Application>
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
		void Close();

	public:
		Debug& GetDebug() { return Debug::GetInstance(); }
		Logger& GetLogger() { return Logger::GetInstance(); }
		Render& GetRender() { return Render::GetInstance(); }
		Gui& GetGui() { return Gui::GetInstance(); }
		Factory& GetFactory() { return Factory::GetInstance(); }
		Assets& GetAssets() { return Assets::GetInstance(); }

	private:
		std::string _executePath;
		std::string _executeDir;
	};
}

#endif // _APPLICATION_HEADER_
