#ifndef _PROJECT_HEADER_
#define _PROJECT_HEADER_

#include <TinyEngine/Core/Reflection/ReflectionObject.hpp>
#include <TinyEngine/Core/Reflection/ReflectionMember.hpp>

namespace TinyEngine
{
	struct ProjectFileLoadParams
	{
		std::wstring path;
	};

	struct ProjectFileCreateParams
	{
		std::wstring path;
		std::string name;
		std::string description;
		std::string author;
		std::string version;
		std::string librariesPath;
	};

	class ProjectFile final : public ReflectionableObject
	{
		REFLECTION_OBJECT_BEGIN(ProjectFile)
			REFLECTION_MEMBER("name", _name)
			REFLECTION_MEMBER("description", _description)
			REFLECTION_MEMBER("author", _author)
			REFLECTION_MEMBER("version", _version)
			REFLECTION_MEMBER("librariesPath", _librariesPath)
		REFLECTION_OBJECT_END

	public:
		ProjectFile() = default;
		~ProjectFile() = default;

	public:
		const std::string& GetName() const { return _name; }
		const std::string& GetDescription() const { return _description; }
		const std::string& GetAuthor() const { return _author; }
		const std::string& GetVersion() const { return _version; }
		const std::string& GetLibrariesPath() const { return _librariesPath; }

		void InitWithCreateParams(const ProjectFileCreateParams& params);

	private:
		std::string _name;
		std::string _description;
		std::string _author;
		std::string _version;
		std::string _librariesPath;
	};

	class Project final
	{
	public:
		Project() = default;
		~Project() = default;

	public:
		void Init();
		void Deinit();

		void Load(const ProjectFileLoadParams& params);
		void Create(const ProjectFileCreateParams& params);

	private:
		void OnLoaded();

	private:
		ProjectFile _projectFile;
	};
}

#endif // _PROJECT_HEADER_
