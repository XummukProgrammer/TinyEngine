#ifndef _GUI_HEADER_
#define _GUI_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Data/Singleton.hpp>

#include <memory>

namespace TinyEngine
{
	class Gui final : public Singleton<Gui>
	{
	public:
		Gui() = default;
		~Gui() = default;

	public:
		void PreInit();
		void Init();
		void Draw();
		void Shutdown();

	public:
		void SetMainWindow(GuiMainWindowWidgetSharedPtr mainWindowPtr);
		GuiMainWindowWidgetSharedPtr GetMainWindow() const;

	private:
		void SettingsIO();
		void SettingsStyle();

	private:
		GuiMainWindowWidgetSharedPtr _mainWindowPtr;
	};
}

#endif // _GUI_HEADER_
