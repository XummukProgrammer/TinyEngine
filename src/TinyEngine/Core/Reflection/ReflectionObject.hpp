#ifndef _REFLECTION_OBJECT_HEADER_
#define _REFLECTION_OBJECT_HEADER_

#include <TinyEngine/Core/Reflection/IReflectionMember.hpp>
#include <TinyEngine/Core/Resources/FileSystem.hpp>
#include <TinyEngine/Core/Reflection/TypeFactory.hpp>

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
		void SaveToFile(std::wstring_view path);

		void LoadFromFile(FileSystem::DirType dirType, std::wstring_view path);
		void LoadFromFile(std::wstring_view path);

	private:
		std::string _name;
		std::vector<std::unique_ptr<IReflectionMember>> _members;
	};

	class ReflectionableObject : public ITypeFactorable
	{
	public:
		ReflectionableObject() = default;
		virtual ~ReflectionableObject() = default;

	public:
		virtual std::unique_ptr<ReflectionObject> CreateReflectionObject() = 0;
	};
}

#define REFLECTION_OBJECT_BEGIN(name) \
	public: \
		virtual std::string GetTypeName() const override { return #name; } \
		static std::string GetStaticTypeName() { return #name; } \
		virtual std::unique_ptr<TinyEngine::ReflectionObject> CreateReflectionObject() override \
		{ \
			auto reflectionObject = std::make_unique<TinyEngine::ReflectionObject>(); \
			reflectionObject->SetName(#name);

#define REFLECTION_OBJECT_END \
			return std::move(reflectionObject); \
		} \
	private:

#define REFLECTION_MEMBER(name, member) \
			{ \
				auto reflectionMember = std::make_unique<ReflectionMember<decltype(member)>>(); \
				reflectionMember->SetName(name); \
				reflectionMember->SetValue(member); \
				reflectionObject->AddMember(std::move(reflectionMember)); \
			}

#endif // _REFLECTION_OBJECT_HEADER_
