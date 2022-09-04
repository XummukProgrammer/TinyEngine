#ifndef _PROPERTIES_HEADER_
#define _PROPERTIES_HEADER_

#include <TinyEngine/Core/Forwards.hpp>

#include <vector>
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

		bool IsEmpty() const { return _members.empty(); }

	private:
		std::vector<std::pair<std::string, IMetaMemberSharedPtr>> _members;
	};
}

#endif // _PROPERTIES_HEADER_
