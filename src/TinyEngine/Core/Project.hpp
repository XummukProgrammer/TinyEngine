#ifndef _PROJECT_HEADER_
#define _PROJECT_HEADER_

#include <TinyEngine/Core/Data/Meta/MetaDefines.hpp>
#include <TinyEngine/Core/States/States.hpp>
#include <TinyEngine/Core/Conditions/Condition.hpp>
#include <TinyEngine/Core/Assets/Common/LinkAsset.hpp>

namespace TinyEngine
{
	class Project final : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(Project)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_name, "Name", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_description, "Description", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_version, "Version", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_states, "States", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_linkAsset, "LinkAsset", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		Project() = default;
		~Project() = default;

	public:
		const std::string& GetName() const { return _name; }
		const std::string& GetDescription() const { return _description; }
		const std::string& GetVersion() const { return _version; }

		States& GetStates() { return _states; }
		const States& GetConstStates() const { return _states; }

		LinkAsset& GetLinkAsset() { return _linkAsset; }
		const LinkAsset& GetConstLinkAsset() const { return _linkAsset; }

		void SetFilePath(std::string_view filePath) { _filePath = filePath; }
		const std::string& GetFilePath() const { return _filePath; }

	private:
		std::string _name = "Game";
		std::string _description = "Default Game";
		std::string _version = "1.0.0";
		States _states;
		LinkAsset _linkAsset;

		std::string _filePath;
	};

	class ProjectUtils
	{
	public:
		static void LoadProject(std::string_view filePath);
		static void SaveProject();
	};
}

#endif // _PROJECT_HEADER_
