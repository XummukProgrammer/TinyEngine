#ifndef _PROJECT_HEADER_
#define _PROJECT_HEADER_

#include <TinyEngine/Core/Data/Meta/MetaDefines.hpp>
#include <TinyEngine/Core/States/States.hpp>
#include <TinyEngine/Core/Conditions/Condition.hpp>
#include <TinyEngine/Core/Assets/Common/AssetHolder.hpp>

namespace TinyEngine
{
	class Project final : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(Project)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_name, "Name", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_description, "Description", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_version, "Version", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_assetHolder, "AssetHolder", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		Project() = default;
		~Project() = default;

	public:
		const std::string& GetName() const { return _name; }
		const std::string& GetDescription() const { return _description; }
		const std::string& GetVersion() const { return _version; }

		StatesSharedPtr GetStates() const;

		AssetHolder& GetAssetHolder() { return _assetHolder; }
		const AssetHolder& GetConstAssetHolder() const { return _assetHolder; }

	private:
		std::string _name = "Game";
		std::string _description = "Default Game";
		std::string _version = "1.0.0";
		AssetHolder _assetHolder;
	};

	class ProjectUtils
	{
	public:
		static void LoadProject(std::string_view filePath);
		static void SaveProject();
	};
}

#endif // _PROJECT_HEADER_
