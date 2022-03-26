#include "RadialLightObject.hpp"

#include <TinyEngine/Core/Core.hpp>

namespace TinyEngine
{
	void RadialLightObject::OnWindowDrawed()
	{
		Core::GetApplication().GetWindow().DrawObject(_radialLight);
	}
}
