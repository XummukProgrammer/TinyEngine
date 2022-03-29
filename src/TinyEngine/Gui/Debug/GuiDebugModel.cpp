#include "GuiDebugModel.hpp"

#include <TinyEngine/Core/Application.hpp>

namespace TinyEngine
{
	std::string GuiDebugModel::GetAppName() const
	{
		return Application::GetInstance().GetName();
	}

	std::string GuiDebugModel::GetAppVersion() const
	{
		return Application::GetInstance().GetVersion();
	}

	float GuiDebugModel::GetDeltaTime() const
	{
		return Application::GetInstance().GetConstWindow().GetDeltaTime();
	}

	unsigned GuiDebugModel::GetFpsCounter() const
	{
		return Application::GetInstance().GetWindow().GetFpsCounter();
	}

	size_t GuiDebugModel::GetLayoutsCount() const
	{
		return Application::GetInstance().GetRender().GetLayoutsCount();
	}

	size_t GuiDebugModel::GetObjectsCount() const
	{
		return Application::GetInstance().GetRender().GetObjectsCount();
	}

	std::vector<std::string> GuiDebugModel::GetActionsIds() const
	{
		return Application::GetInstance().GetConstActionsQueue().GetActionsIds();
	}
}
