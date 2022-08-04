#include "Assets.hpp"

namespace TinyEngine
{
	void Assets::LoadFromFile()
	{
		SerializationUtils::LoadRootFromFile(ArchiveFormat::Xml, "root.xml", &_holder);
		_holder.OnLoad();
	}
}
