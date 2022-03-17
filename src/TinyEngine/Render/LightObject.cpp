#include "LightObject.hpp"

#include <TinyEngine/Core/Window.hpp>

#include <Candle/RadialLight.hpp>

namespace TinyEngine::Render
{
	LightObject::LightObject()
		: _radialLight(std::make_shared<candle::RadialLight>())
	{
	}

	void LightObject::OnDeinit()
	{ 
		_radialLight.reset();
	}

	void LightObject::OnDraw()
	{ 
		Core::Window::GetInstance().Draw(*_radialLight.get());
	}

	LightObject::RadialLightPtr LightObject::GetRadialLight() const
	{
		return _radialLight;
	}

	void LightObject::SetRange(float range)
	{
		_radialLight->setRange(range);
	}

	float LightObject::GetRange() const
	{
		return _radialLight->getRange();
	}

	void LightObject::SetPosition(const sf::Vector2f& position)
	{ 
		_radialLight->setPosition(position);
	}

	const sf::Vector2f& LightObject::GetPosition() const
	{
		return _radialLight->getPosition();
	}
}
