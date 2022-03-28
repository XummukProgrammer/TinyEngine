#include "VisualObject.hpp"

#include <TinyEngine/Core/Application.hpp>

namespace TinyEngine
{
	void VisualObject::OnWindowDrawed()
	{ 
		Application::GetInstance().GetWindow().DrawObject(_sprite);
	}

	void VisualObject::SetTexture(std::string_view assetId)
	{ 
		const auto& textureAssets = Application::GetInstance().GetAllAssets().GetConstTextureAssets();

		if (!textureAssets.HasAsset(assetId))
		{
			_sprite.setTexture(sf::Texture());
			return;
		}
		
		_sprite.setTexture(textureAssets.GetAsset(assetId)->GetTexture());
	}

	void VisualObject::SetTextureRect(const sf::IntRect& rect)
	{ 
		_sprite.setTextureRect(rect);
	}
}
