#include "Assets.hpp"

#include <TinyEngine/Core/Assets/AssetLoader.hpp>
#include <TinyEngine/Core/Assets/AssetTexture.hpp>

#include <TinyEngine/Core/Logger.hpp>

#include <fmt/format.h>

namespace TinyEngine
{
	void Assets::LoadFromFile(std::string_view filePath)
	{
		// Костыли для автоматического добавления классов в фабрику.
		// Без явного объявления нужные классы просто не попадают в экзешник.
		TinyEngine::AssetLoader costilLoader;
		TinyEngine::AssetTexture costilSfmlTexture;

		TINY_ENGINE_PRINT_INFO(fmt::format("Load assets file: {}", filePath));
		SerializationUtils::LoadRootFromFile(ArchiveFormat::Xml, filePath, &_holder);
		_holder.OnAssetLoad();
		TINY_ENGINE_PRINT_INFO("Assets file loaded!");
	}
}
