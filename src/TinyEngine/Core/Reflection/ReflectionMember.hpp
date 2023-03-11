#ifndef _REFLECTION_MEMBER_HEADER_
#define _REFLECTION_MEMBER_HEADER_

#include <TinyEngine/Core/Reflection/IReflectionMember.hpp>
#include <TinyEngine/Core/Reflection/ReflectionObject.hpp>

namespace TinyEngine
{
	template<typename T>
	class ReflectionMember final : public IReflectionMember
	{
	public:
		ReflectionMember() = default;
		~ReflectionMember() = default;

	public:
		void SetName(std::string_view name) override { _name = name; }
		const std::string& GetName() const override { return _name; }

		void Serialize(IOutputArchive* archive) override;
		void Deserialize(IInputArchive* archive) override;

	public:
		void SetValue(T& value) { _value = &value; }
		const T& GetValue() const { return *_value; }
		T& GetRefValue() { return *_value; }

	private:
		std::string _name;
		T* _value;
	};

	template<typename T>
	void ReflectionMember<T>::Serialize(IOutputArchive* archive)
	{
		ReflectionMemberVisitor<T>::Serialize(_value, GetName(), archive);
	}

	template<typename T>
	void ReflectionMember<T>::Deserialize(IInputArchive* archive)
	{
		ReflectionMemberVisitor<T>::Deserialize(_value, GetName(), archive);
	}

	template<typename T>
	class ReflectionMemberVisitor
	{
	public:
		static void Serialize(T* value, std::string_view name, IOutputArchive* archive)
		{
			if (std::is_base_of_v<ReflectionObjectCreator, T>)
			{
				ReflectionMemberVisitor<ReflectionObjectCreator>::Serialize(value, name, archive);
			}
		}

		static void Deserialize(T* value, std::string_view name, IInputArchive* archive)
		{
			if (std::is_base_of_v<ReflectionObjectCreator, T>)
			{
				ReflectionMemberVisitor<ReflectionObjectCreator>::Deserialize(value, name, archive);
			}
		}
	};

	template<>
	class ReflectionMemberVisitor<int>
	{
	public:
		static void Serialize(int* value, std::string_view name, IOutputArchive* archive)
		{
			archive->WriteInt(name, *value);
		}

		static void Deserialize(int* value, std::string_view name, IInputArchive* archive)
		{
			*value = archive->ReadInt(name);
		}
	};

	template<>
	class ReflectionMemberVisitor<float>
	{
	public:
		static void Serialize(float* value, std::string_view name, IOutputArchive* archive)
		{
			archive->WriteFloat(name, *value);
		}

		static void Deserialize(float* value, std::string_view name, IInputArchive* archive)
		{
			*value = archive->ReadFloat(name);
		}
	};

	template<>
	class ReflectionMemberVisitor<std::string>
	{
	public:
		static void Serialize(std::string* value, std::string_view name, IOutputArchive* archive)
		{
			archive->WriteString(name, *value);
		}

		static void Deserialize(std::string* value, std::string_view name, IInputArchive* archive)
		{
			*value = archive->ReadString(name);
		}
	};

	template<>
	class ReflectionMemberVisitor<ReflectionObjectCreator>
	{
	public:
		static void Serialize(ReflectionObjectCreator* value, std::string_view name, IOutputArchive* archive)
		{
			auto reflectionObjectCreator = value->CreateReflectionObject();
			archive->WriteKey(name);
			reflectionObjectCreator->Serialize(archive);
			archive->EndKey();
		}

		static void Deserialize(ReflectionObjectCreator* value, std::string_view name, IInputArchive* archive)
		{
			auto reflectionObjectCreator = value->CreateReflectionObject();
			archive->ReadKey(name);
			reflectionObjectCreator->Deserialize(archive);
			archive->EndKey();
		}
	};
}

#endif // _REFLECTION_MEMBER_HEADER_
