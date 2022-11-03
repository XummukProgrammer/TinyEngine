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

	enum class LogType
	{
		Info = 1 << 1,
		Assert = 1 << 2,
		Verify = 1 << 3,
		Error = 1 << 4,
		All = Info | Assert | Verify | Error
	};
}

#endif // _CONSTANTS_HEADER_
