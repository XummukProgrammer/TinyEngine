#ifndef _TYPE_FACTORY_HEADER_
#define _TYPE_FACTORY_HEADER_

#include <map>
#include <string>
#include <functional>
#include <memory>

namespace TinyEngine
{
	class ITypeFactorable
	{
	public:
		ITypeFactorable() = default;
		virtual ~ITypeFactorable() = default;

	public:
		virtual std::string GetTypeName() const = 0;
		static std::string GetStaticTypeName() { return ""; }
	};

	class TypeFactory final
	{
	public:
		TypeFactory() = default;
		~TypeFactory() = default;

	private:

	};
}

#endif // _TYPE_FACTORY_HEADER_
