#ifndef _VISUAL_OBJECT_HEADER_
#define _VISUAL_OBJECT_HEADER_

#include <TinyEngine/Render/IObject.hpp>

#include <SFML/Graphics.hpp>

namespace TinyEngine
{
	class VisualObject final : public IObject
	{
	public:
		VisualObject() = default;
		~VisualObject() = default;

	public:
		void OnWindowUpdated() override;
		void OnWindowDrawed() override;

	private:
		sf::Sprite _sprite;
	};
}

#endif // _VISUAL_OBJECT_HEADER_
