#ifndef _CONSTANTS_HEADER_
#define _CONSTANTS_HEADER_

namespace TinyEngine
{
	enum class DirType
	{
		Execute,
		Root,
		Assets,
		Logs
	};

	enum class ArchiveFormat
	{
		Xml
	};

	enum class MetaMemberFlag
	{
		Save = 1 << 1,
		Load = 1 << 2,
		Editor = 1 << 3,
		Default = Save | Load | Editor
	};
}

#endif // _CONSTANTS_HEADER_
