#include "CloseState.hpp"

#include <TinyEngine/Core/Application.hpp>

namespace TinyEngine
{
	void CloseState::OnEnter()
	{
		Application::GetInstance()->Close();
	}
}
