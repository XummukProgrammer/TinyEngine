#include "VisualObject.hpp"

#include <TinyEngine/Core/Core.hpp>

#include <TinyEngine/Core/Core.hpp>

namespace TinyEngine
{
	void VisualObject::OnWindowDrawed()
	{ 
		Core::GetApplication().GetWindow().DrawObject(_sprite);
	}

	void VisualObject::SetTexture(std::string_view assetId)
	{ 
		const auto& textureAssets = Core::GetApplication().GetAllAssets().GetConstTextureAssets();

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
