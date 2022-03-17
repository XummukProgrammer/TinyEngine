#ifndef _LIGHT_OBJECT_HEADER_
#define _LIGHT_OBJECT_HEADER_

#include <TinyEngine/Render/IObject.hpp>

#include <SFML/System/Vector2.hpp>

#include <memory>

namespace candle
{
	class RadialLight;
}

namespace TinyEngine::Render
{
	class LightObject final : public IObject
	{
	public:
		using RadialLightPtr = std::shared_ptr<candle::RadialLight>;

	public:
		LightObject();
		~LightObject() = default;

	public:
		void OnDeinit() override;

		void OnDraw() override;

	public:
		RadialLightPtr GetRadialLight() const;

		void SetRange(float range);
		float GetRange() const;

		void SetPosition(const sf::Vector2f& position);
		const sf::Vector2f& GetPosition() const;

	private:
		RadialLightPtr _radialLight;
	};
}

#endif // _LIGHT_OBJECT_HEADER_
