#include "RadialLightObject.hpp"

#include <TinyEngine/Core/Core.hpp>

namespace TinyEngine
{
	void RadialLightObject::OnWindowUpdated()
	{
		_radialLight.setRange(100.f);
	}

	void RadialLightObject::OnWindowDrawed()
	{
		Core::GetApplication().GetWindow().DrawObject(_radialLight);
	}
}
