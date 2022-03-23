#include "GuiDebugModel.hpp"

#include <TinyEngine/Core/Core.hpp>

namespace TinyEngine
{
	std::string GuiDebugModel::GetAppName() const
	{
		return Core::GetApplication().GetName();
	}

	std::string GuiDebugModel::GetAppVersion() const
	{
		return Core::GetApplication().GetVersion();
	}

	unsigned GuiDebugModel::GetFpsCounter() const
	{
		return Core::GetApplication().GetWindow().GetFpsCounter();
	}
}
