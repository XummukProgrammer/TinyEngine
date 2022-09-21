#include "Assets.hpp"

#include <TinyEngine/Core/Assets/AssetLoader.hpp>
#include <TinyEngine/Core/Assets/AssetTexture.hpp>

namespace TinyEngine
{
	void Assets::LoadFromFile()
	{
		// Костыли для автоматического добавления классов в фабрику.
		// Без явного объявления нужные классы просто не попадают в экзешник.
		TinyEngine::AssetLoader costilLoader;
		TinyEngine::AssetTexture costilSfmlTexture;

		SerializationUtils::LoadRootFromFile(ArchiveFormat::Xml, "root.xml", &_holder);
		_holder.OnAssetLoad();
	}
}
