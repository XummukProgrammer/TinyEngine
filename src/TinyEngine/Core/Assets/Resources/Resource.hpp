#ifndef _RESOURCE_HEADER_
#define _RESOURCE_HEADER_

namespace TinyEngine
{
	class Resource
	{
	public:
		Resource() = default;
		virtual ~Resource() = default;

	public:
		virtual void Unload() = 0;
	};
}

#endif // _RESOURCE_HEADER_
