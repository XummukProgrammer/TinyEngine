#ifndef _PROPERTIES_HEADER_
#define _PROPERTIES_HEADER_

#include <TinyEngine/Core/Forwards.hpp>

#include <map>
#include <string>
#include <functional>

namespace TinyEngine
{
	class MetaMembers final
	{
	public:
		using OnForEach = std::function<void(std::string_view, IMetaMemberSharedPtr)>;

	public:
		MetaMembers() = default;
		~MetaMembers() = default;

	public:
		void AddMember(IMetaMemberSharedPtr member);
		IMetaMemberSharedPtr GetMember(std::string_view id) const;

		void ForEach(const OnForEach& callback) const;

		void LoadFromArchive(InputArchivePtr archive);
		void SaveToArchive(OutputArchivePtr archive);

		void AddGuiWidgetsToContainer(GuiWidgetContainerPtr container);

	private:
		std::map<std::string, IMetaMemberSharedPtr> _members;
	};
}

#endif // _PROPERTIES_HEADER_
