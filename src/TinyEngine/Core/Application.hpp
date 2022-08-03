#ifndef _APPLICATION_HEADER_
#define _APPLICATION_HEADER_

#include <TinyEngine/Core/Debug.hpp>
#include <TinyEngine/Core/Logger.hpp>
#include <TinyEngine/Render/Render.hpp>
#include <TinyEngine/Gui/Gui.hpp>
#include <TinyEngine/Data/Factory.hpp>
#include <TinyEngine/Core/Assets/Assets.hpp>
#include <TinyEngine/Core/FileSystem.hpp>

#include <TinyEngine/Render/SfmlRender.hpp>

namespace TinyEngine
{
	class Application final : public Singleton<Application>
	{
	public:
		Application() = default;
		~Application() = default;

	public:
		void Execute();

		void LoggerSaveToFile();
		void Close();

	public:
		Debug& GetDebug() { return Debug::GetInstance(); }
		Logger& GetLogger() { return Logger::GetInstance(); }
		Render& GetRender() { return Render::GetInstance(); }
		Gui& GetGui() { return Gui::GetInstance(); }
		Factory& GetFactory() { return Factory::GetInstance(); }
		Assets& GetAssets() { return Assets::GetInstance(); }
		FileSystem& GetFileSystem() { return FileSystem::GetInstance(); }
	};
}

#endif // _APPLICATION_HEADER_
