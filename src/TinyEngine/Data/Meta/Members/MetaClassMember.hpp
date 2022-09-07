#ifndef _META_CLASS_MEMBER_HEADER_
#define _META_CLASS_MEMBER_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Data/Meta/Members/IMetaMember.hpp>

namespace TinyEngine
{
	class MetaClassMemberWrapper : public IMetaMember
	{
	public:
		MetaClassMemberWrapper(std::string_view name, std::string_view description, MetaClassPtr metaClass);
		~MetaClassMemberWrapper() = default;

	public:
		void LoadFromArchive(InputArchivePtr archive) override;
		void SaveToArchive(OutputArchivePtr archive) override;

		void AddGuiWidget(GuiWidgetContainerPtr container, IRenderWindowSharedPtr window) override;

	private:
		MetaClassPtr _metaClass;
	};
}

#endif // _META_CLASS_MEMBER_HEADER_
