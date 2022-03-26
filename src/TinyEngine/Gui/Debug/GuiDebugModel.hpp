#ifndef _GUI_DEBUG_MODEL_HEADER_
#define _GUI_DEBUG_MODEL_HEADER_

#include <TinyEngine/Gui/GuiModel.hpp>

#include <string>

namespace TinyEngine
{
	class GuiDebugModel final : public GuiModel
	{
	public:
		GuiDebugModel() = default;
		~GuiDebugModel() = default;

	public:
		// Получить название приложения.
		std::string GetAppName() const;
		// Получить версию приложения.
		std::string GetAppVersion() const;
		// Получить счётчик FPS.
		unsigned GetFpsCounter() const;
		// Получить кол-во слоёв.
		size_t GetLayoutsCount() const;
	};
}

#endif // _GUI_DEBUG_MODEL_HEADER_
