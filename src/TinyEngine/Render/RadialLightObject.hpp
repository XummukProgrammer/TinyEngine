#ifndef _RADIAL_LIGHT_OBJECT_HEADER_
#define _RADIAL_LIGHT_OBJECT_HEADER_

#include <TinyEngine/Render/IObject.hpp>

#include <Candle/RadialLight.hpp>

namespace TinyEngine
{
	// Класс с обычным светом.
	class RadialLightObject final : public IObject
	{
	public:
		RadialLightObject() = default;
		~RadialLightObject() = default;

	public:
		// Окно обновляется.
		void OnWindowUpdated() override;
		// Окно рисуется.
		void OnWindowDrawed() override;

	private:
		// Свет.
		candle::RadialLight _radialLight;
	};
}

#endif // _RADIAL_LIGHT_OBJECT_HEADER_
