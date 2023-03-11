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

	public:
		template<typename T, typename = std::enable_if_t<std::is_base_of_v<ITypeFactorable, T>>> 
		void RegisterType()
		{
			_registeredTypes[T::GetStaticTypeName()] = []()
			{
				return std::make_shared<T>();
			};
		}

		std::shared_ptr<ITypeFactorable> CreateType(std::string_view typeName) const;

	private:
		std::map<std::string, std::function<std::shared_ptr<ITypeFactorable>()>> _registeredTypes;
	};
}

#endif // _TYPE_FACTORY_HEADER_
