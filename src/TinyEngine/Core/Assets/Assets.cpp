#include "Assets.hpp"

#include <TinyEngine/Core/Assets/AssetLoader.hpp>

namespace TinyEngine
{
	void Assets::LoadFromFile()
	{
		SerializationUtils::LoadRootFromFile(SerializationUtils::ArchiveFormat::Xml, "root.xml", &_holder);
		_holder.OnLoad();
	}
}
