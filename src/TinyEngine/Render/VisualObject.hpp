#ifndef _VISUAL_OBJECT_HEADER_
#define _VISUAL_OBJECT_HEADER_

#include <TinyEngine/Render/IObject.hpp>

#include <SFML/Graphics.hpp>

#include <string>

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

	public:
		// Установить текстуру из текстурных ассетов.
		void SetTexture(std::string_view assetId);
		// Установить область текстуры.
		void SetTextureRect(const sf::IntRect& rect);

	private:
		// Спрайт.
		sf::Sprite _sprite;
	};
}

#endif // _VISUAL_OBJECT_HEADER_
