#ifndef _PROPERTIES_HEADER_
#define _PROPERTIES_HEADER_

#include <TinyEngine/Core/Forwards.hpp>

#include <map>
#include <string>
#include <functional>

namespace TinyEngine
{
	class Properties final
	{
	public:
		using OnForEach = std::function<void(std::string_view, IPropertySharedPtr)>;

	public:
		Properties() = default;
		~Properties() = default;

	public:
		void AddProperty(IPropertySharedPtr property);
		IPropertySharedPtr GetProperty(std::string_view id) const;

		void ForEach(const OnForEach& callback) const;

		void LoadFromArchive(InputArchivePtr archive);
		void SaveToArchive(OutputArchivePtr archive);

	private:
		std::map<std::string, IPropertySharedPtr> _properties;
	};
}

#endif // _PROPERTIES_HEADER_
