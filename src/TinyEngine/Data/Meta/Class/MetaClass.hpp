﻿#ifndef _META_CLASS_HEADER_
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
		virtual const std::string GetName() const = 0;
		static std::string GetStaticName() { return ""; }

		MetaMembers& GetMembers(bool isCheckLoaded = true);
		const MetaMembers& GetConstMembers() const { return _members; }

		bool IsLoaded() const;

		void AddGuiWidgetsToContainer(GuiWidgetContainerPtr container);

	protected:
		// Временно без = 0, после перевода сериализации на новую систему вернуть 0 обратно.
		virtual void OnLoad() {}

	private:
		void TryLoad();

	private:
		MetaMembers _members;
	};
}

#endif // _META_CLASS_HEADER_
