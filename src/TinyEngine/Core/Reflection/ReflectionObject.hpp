#ifndef _REFLECTION_OBJECT_HEADER_
#define _REFLECTION_OBJECT_HEADER_

#include <TinyEngine/Core/Reflection/ReflectionMember.hpp>
#include <TinyEngine/Core/Resources/FileSystem.hpp>

#include <vector>
#include <memory>
#include <functional>

namespace TinyEngine
{
	class ReflectionObject final
	{
	public:
		ReflectionObject() = default;
		~ReflectionObject() = default;

	public:
		void SetName(std::string_view name) { _name = name; }
		const std::string& GetName() const { return _name; }

		void AddMember(std::unique_ptr<IReflectionMember>&& member);
		bool HasMember(std::string_view name) const;
		IReflectionMember* GetMember(std::string_view name) const;
		void ForEachMembers(const std::function<void(IReflectionMember* member)> func);

		void Serialize(IOutputArchive* archive);
		void Deserialize(IInputArchive* archive);

		void SaveToFile(FileSystem::DirType dirType, std::wstring_view path);
		void LoadFromFile(FileSystem::DirType dirType, std::wstring_view path);

	private:
		std::string _name;
		std::vector<std::unique_ptr<IReflectionMember>> _members;
	};
}

#endif // _REFLECTION_OBJECT_HEADER_
