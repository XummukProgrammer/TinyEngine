#ifndef _META_CLASS_HEADER_
#define _META_CLASS_HEADER_

#include <TinyEngine/Data/Meta/Members/MetaMembers.hpp>

#include <string>

namespace TinyEngine
{
	class MetaClass
	{
	public:
		MetaClass() = default;
		virtual ~MetaClass() = default;

	public:
		virtual const std::string GetClassName() const = 0;
		static std::string GetStaticClassName() { return ""; }

		virtual MetaClassSharedPtr CreateSharedPtr() const = 0;
		static MetaClassSharedPtr CreateStaticSharedPtr() { return nullptr; }

		MetaMembers& GetMembers(bool isCheckLoaded = true);
		const MetaMembers& GetConstMembers() const { return _members; }

		bool IsLoaded() const;

		void AddGuiWidgetsToContainer(GuiWidgetContainerPtr container);

	protected:
		virtual void OnLoad() = 0;

	private:
		void TryLoad();

	private:
		MetaMembers _members;
	};
}

#endif // _META_CLASS_HEADER_
