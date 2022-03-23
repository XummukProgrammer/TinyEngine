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
		std::string GetAppName() const;
		std::string GetAppVersion() const;
	};
}

#endif // _GUI_DEBUG_MODEL_HEADER_
