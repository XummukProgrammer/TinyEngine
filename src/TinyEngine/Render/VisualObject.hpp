#ifndef _VISUAL_OBJECT_HEADER_
#define _VISUAL_OBJECT_HEADER_

#include <TinyEngine/Render/IObject.hpp>

#include <SFML/Graphics.hpp>

namespace TinyEngine
{
	// Визуальный объект (Спрайт).
	class VisualObject final : public IObject
	{
	public:
		VisualObject() = default;
		~VisualObject() = default;

	public:
		// Окно обновляется.
		void OnWindowUpdated() override;
		// Окно рисуется.
		void OnWindowDrawed() override;

	private:
		// Спрайт.
		sf::Sprite _sprite;
	};
}

#endif // _VISUAL_OBJECT_HEADER_
