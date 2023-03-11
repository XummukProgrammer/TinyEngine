#ifndef _REFLECTION_MEMBER_HEADER_
#define _REFLECTION_MEMBER_HEADER_

#include <TinyEngine/Core/Reflection/IReflectionMember.hpp>
#include <TinyEngine/Core/Reflection/ReflectionObject.hpp>
#include <TinyEngine/Core/Application/Application.hpp>

#include <fmt/format.h>

#include <vector>
#include <map>
#include <memory>

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
			if constexpr (std::is_base_of_v<ReflectionObjectCreator, T>)
			{
				ReflectionMemberVisitor<ReflectionObjectCreator>::Serialize(value, name, archive);
			}
		}

		static void Deserialize(T* value, std::string_view name, IInputArchive* archive)
		{
			if constexpr (std::is_base_of_v<ReflectionObjectCreator, T>)
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

	template<typename T>
	class ReflectionMemberVisitor<std::vector<T>>
	{
	public:
		static void Serialize(std::vector<T>* values, std::string_view name, IOutputArchive* archive)
		{
			archive->WriteKey(name);
			archive->WriteInt("size", static_cast<int>(values->size()));

			int index = 0;
			for (auto& value : *values)
			{
				archive->WriteKey(fmt::format("element_{}", index));
				ReflectionMemberVisitor<T>::Serialize(&value, "value", archive);
				archive->EndKey();

				++index;
			}

			archive->EndKey();
		}

		static void Deserialize(std::vector<T>* values, std::string_view name, IInputArchive* archive)
		{
			archive->ReadKey(name);
			
			const int size = archive->ReadInt("size");
			for (int i = 0; i < size; ++i)
			{
				archive->ReadKey(fmt::format("element_{}", i));
				T value{};
				ReflectionMemberVisitor<T>::Deserialize(&value, "value", archive);
				values->push_back(std::move(value));
				archive->EndKey();
			}

			archive->EndKey();
		}
	};

	template<typename K, typename V>
	class ReflectionMemberVisitor<std::map<K, V>>
	{
	public:
		static void Serialize(std::map<K, V>* values, std::string_view name, IOutputArchive* archive)
		{
			archive->WriteKey(name);
			archive->WriteInt("size", static_cast<int>(values->size()));

			int index = 0;
			for (auto& [ key, value ] : *values)
			{
				archive->WriteKey(fmt::format("element_{}", index));
				K constKey = key;
				ReflectionMemberVisitor<K>::Serialize(&constKey, "key", archive);
				ReflectionMemberVisitor<V>::Serialize(&value, "value", archive);
				archive->EndKey();

				++index;
			}

			archive->EndKey();
		}

		static void Deserialize(std::map<K, V>* values, std::string_view name, IInputArchive* archive)
		{
			archive->ReadKey(name);

			const int size = archive->ReadInt("size");
			for (int i = 0; i < size; ++i)
			{
				archive->ReadKey(fmt::format("element_{}", i));
				K key{};
				V value{};
				ReflectionMemberVisitor<K>::Deserialize(&key, "key", archive);
				ReflectionMemberVisitor<V>::Deserialize(&value, "value", archive);
				values->emplace(key, value);
				archive->EndKey();
			}

			archive->EndKey();
		}
	};

	template<typename T>
	class ReflectionMemberVisitor<std::shared_ptr<T>>
	{
	public:
		static void Serialize(std::shared_ptr<T>* value, std::string_view name, IOutputArchive* archive)
		{
			archive->WriteKey(name);
			archive->WriteKey("ptr");

			T* rawPointer = value->get();

			if constexpr (std::is_base_of_v<ITypeFactorable, T>)
			{
				const std::string type = dynamic_cast<ITypeFactorable*>(rawPointer)->GetTypeName();
				archive->WriteString("type", type);
			}

			ReflectionMemberVisitor<T>::Serialize(rawPointer, "value", archive);
			archive->EndKey();
			archive->EndKey();
		}

		static void Deserialize(std::shared_ptr<T>* value, std::string_view name, IInputArchive* archive)
		{
			archive->ReadKey(name);
			archive->ReadKey("ptr");
			
			if constexpr (std::is_base_of_v<ITypeFactorable, T>)
			{
				const std::string type = archive->ReadString("type");
				*value = std::dynamic_pointer_cast<T>(Application::GetSingleton().GetContext().GetTypeFactory().CreateType(type));
			}
			else
			{
				*value = std::make_shared<T>();
			}

			ReflectionMemberVisitor<T>::Deserialize(value->get(), "value", archive);

			archive->EndKey();
			archive->EndKey();
		}
	};
}

#endif // _REFLECTION_MEMBER_HEADER_
