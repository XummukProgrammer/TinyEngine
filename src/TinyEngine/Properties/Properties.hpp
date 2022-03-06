#ifndef _PROPERTIES_HEADER_
#define _PROPERTIES_HEADER_

#include <string>
#include <map>
#include <memory>

namespace TinyEngine::Properties
{
	namespace Data
	{
		class IntProperty;
	}

	class IProperty;

	class Properties final
	{
	public:
		using IPropertyPtr = std::shared_ptr<IProperty>;
		using IntPropertyPtr = std::shared_ptr<Data::IntProperty>;

	public:
		Properties() = default;
		~Properties() = default;

	public:
		void SetIntProperty(std::string_view key, int value);
		int GetIntProperty(std::string_view key, int default) const;

	private:
		void SetProperty(std::string_view key, IPropertyPtr&& property);
		IPropertyPtr GetProperty(std::string_view key) const;

		IntPropertyPtr GetIntProperty(std::string_view key) const;

	public:
		std::map<std::string, IPropertyPtr> _properties;
	};
}

#endif // _PROPERTIES_HEADER_
