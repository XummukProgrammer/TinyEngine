#include "RadialLightObject.hpp"

#include <TinyEngine/Core/Application.hpp>

namespace TinyEngine
{
	void RadialLightObject::OnWindowDrawed()
	{
		Application::GetInstance().GetWindow().DrawObject(_radialLight);
	}
}
