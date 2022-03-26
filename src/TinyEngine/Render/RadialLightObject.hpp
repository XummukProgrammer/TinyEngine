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
		// Окно рисуется.
		void OnWindowDrawed() override;

	public:
		void SetRange(float range) { _radialLight.setRange(range); }
		float GetRange() const { return _radialLight.getRange(); }

		void SetIntensity(float intensity) { _radialLight.setIntensity(intensity); }
		float GetIntensity() const { return _radialLight.getIntensity(); }

		void SetBeamAngle(float angle) { _radialLight.setBeamAngle(angle); }
		float GetBeamAngle() const { return _radialLight.getBeamAngle(); }

		void SetColor(const sf::Color& color) { _radialLight.setColor(color); }
		const sf::Color& GetColor() const { return _radialLight.getColor(); }

		void SetPosition(const sf::Vector2f& position) { _radialLight.setPosition(position); }
		const sf::Vector2f& GetPosition() const { return _radialLight.getPosition(); }

		void SetScale(const sf::Vector2f& factors) { _radialLight.setScale(factors); }
		const sf::Vector2f& GetScale() { return _radialLight.getScale(); }

		void SetOrigin(const sf::Vector2f& origin) { _radialLight.setOrigin(origin); }
		const sf::Vector2f& GetOrigin() const { return _radialLight.getOrigin(); }

		void SetRotation(float rotation) { _radialLight.setRotation(rotation); }
		float GetRotation() const { return _radialLight.getRotation(); }

		const sf::FloatRect& GetGlobalBounds() const { return _radialLight.getGlobalBounds(); }

		void SetFade(bool fade) { _radialLight.setFade(fade); }
		bool GetFade() const { return _radialLight.getFade(); }

	private:
		// Свет.
		candle::RadialLight _radialLight;
	};
}

#endif // _RADIAL_LIGHT_OBJECT_HEADER_
