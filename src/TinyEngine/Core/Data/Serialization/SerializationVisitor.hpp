#ifndef _SERIALIAZTION_VISITOR_HEADER_
#define _SERIALIAZTION_VISITOR_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Data/Serialization/Serialization.hpp>
#include <TinyEngine/Core/Data/Factory.hpp>
#include <TinyEngine/Core/Data/Meta/Class/MetaClass.hpp>

#include <magic_enum.hpp>

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <utility>

namespace TinyEngine
{
	template<typename T>
	class SerializationVisitor
	{
	public:
		static void Save(OutputArchivePtr archive, std::string_view id, T* data) 
		{
			if constexpr (std::is_base_of_v<MetaClass, T>)
			{
				SerializationVisitor<MetaClass>::Save(archive, id, data);
			}
			else if constexpr (std::is_enum_v<T>)
			{
				SerializationVisitorUniqueImpl::EnumSave(archive, id, data);
			}
		}

		static void Load(InputArchivePtr archive, std::string_view id, T* data) 
		{
			if constexpr (std::is_base_of_v<MetaClass, T>)
			{
				SerializationVisitor<MetaClass>::Load(archive, id, data);
			}
			else if constexpr (std::is_enum_v<T>)
			{
				SerializationVisitorUniqueImpl::EnumLoad(archive, id, data);
			}
		}
	};

	template<>
	class SerializationVisitor<bool>
	{
	public:
		static void Save(OutputArchivePtr archive, std::string_view id, bool* data) 
		{
			archive->ToVariable(id);
			archive->SetBool(*data);
		}

		static void Load(InputArchivePtr archive, std::string_view id, bool* data) 
		{
			archive->ToVariable(id);
			*data = archive->GetBool();
		}
	};

	template<>
	class SerializationVisitor<int>
	{
	public:
		static void Save(OutputArchivePtr archive, std::string_view id, int* data) 
		{
			archive->ToVariable(id);
			archive->SetInt(*data);
		}

		static void Load(InputArchivePtr archive, std::string_view id, int* data) 
		{
			archive->ToVariable(id);
			*data = archive->GetInt();
		}
	};

	template<>
	class SerializationVisitor<float>
	{
	public:
		static void Save(OutputArchivePtr archive, std::string_view id, float* data) 
		{
			archive->ToVariable(id);
			archive->SetFloat(*data);
		}

		static void Load(InputArchivePtr archive, std::string_view id, float* data) 
		{
			archive->ToVariable(id);
			*data = archive->GetFloat();
		}
	};

	template<>
	class SerializationVisitor<std::string>
	{
	public:
		static void Save(OutputArchivePtr archive, std::string_view id, std::string* data) 
		{
			archive->ToVariable(id);
			archive->SetString(*data);
		}

		static void Load(InputArchivePtr archive, std::string_view id, std::string* data) 
		{
			archive->ToVariable(id);
			*data = archive->GetString();
		}
	};

	template<>
	class SerializationVisitor<MetaClass>
	{
	public:
		static void Save(OutputArchivePtr archive, std::string_view id, MetaClassPtr data) 
		{
			if (data && archive->ToSection(id))
			{
				data->GetMembers().SaveToArchive(archive);

				if (!id.empty())
				{
					archive->EndSection();
				}
			}
		}

		static void Load(InputArchivePtr archive, std::string_view id, MetaClassPtr data) 
		{
			if (archive->ToSection(id))
			{
				data->GetMembers().LoadFromArchive(archive);

				if (!id.empty())
				{
					archive->EndSection();
				}
			}
		}
	};

	template<typename T>
	class SerializationVisitor<std::vector<T>>
	{
	public:
		static void Save(OutputArchivePtr archive, std::string_view id, std::vector<T>* data) 
		{
			auto& dataRef = *data;

			for (auto& dataElement : dataRef)
			{
				if (archive->ToItem(id))
				{
					SerializationVisitor<T>::Save(archive, SerializationVisitorUtils::GetValueStringForContainer<T>(), &dataElement);

					archive->EndItem();
				}
			}
		}

		static void Load(InputArchivePtr archive, std::string_view id, std::vector<T>* data) 
		{
			if (archive->ToItem(id))
			{
				auto& dataRef = *data;

				do
				{
					T value;
					SerializationVisitor<T>::Load(archive, SerializationVisitorUtils::GetValueStringForContainer<T>(), &value);
					dataRef.push_back(value);
				}
				while (archive->ToNextItem(id));

				archive->EndItem();
			}
		}
	};

	template<typename K, typename V>
	class SerializationVisitor<std::map<K, V>>
	{
	public:
		static void Save(OutputArchivePtr archive, std::string_view id, std::map<K, V>* data) 
		{
			auto& dataRef = *data;

			for (auto& [ dataKey, dataElement ] : dataRef)
			{
				if (archive->ToItem(id))
				{
					auto key = dataKey;
					SerializationVisitor<K>::Save(archive, "key", &key);
					SerializationVisitor<V>::Save(archive, SerializationVisitorUtils::GetValueStringForContainer<V>(), &dataElement);

					archive->EndItem();
				}
			}
		}

		static void Load(InputArchivePtr archive, std::string_view id, std::map<K, V>* data) 
		{
			if (archive->ToItem(id))
			{
				auto& dataRef = *data;

				do
				{
					K key;
					V value;
					SerializationVisitor<K>::Load(archive, "key", &key);
					SerializationVisitor<V>::Load(archive, SerializationVisitorUtils::GetValueStringForContainer<V>(), &value);
					dataRef[key] = value;
				}
				while (archive->ToNextItem(id));

				archive->EndItem();
			}
		}
	};

	template<typename T>
	class SerializationVisitor<std::shared_ptr<T>>
	{
	public:
		static void Save(OutputArchivePtr archive, std::string_view id, std::shared_ptr<T>* data) 
		{
			auto rawPointer = data->get();

			if (rawPointer)
			{
				if (archive->ToSection(id))
				{
					if (archive->ToItem("pointer"))
					{
						std::string type = rawPointer->GetClassName();
						SerializationVisitor<std::string>::Save(archive, "type", &type);

						SerializationVisitor<T>::Save(archive, "", rawPointer);

						archive->EndItem();
					}

					if (!id.empty())
					{
						archive->EndSection();
					}
				}
			}
		}

		static void Load(InputArchivePtr archive, std::string_view id, std::shared_ptr<T>* data) 
		{
			if (archive->ToSection(id))
			{
				if (archive->ToItem("pointer"))
				{
					std::string type;
					SerializationVisitor<std::string>::Load(archive, "type", &type);

					if (*data = Factory::GetInstance()->Create<T>(type))
					{
						auto rawPointer = data->get();
						
						SerializationVisitor<T>::Load(archive, "", rawPointer);
					}

					archive->EndItem();
				}

				if (!id.empty())
				{
					archive->EndSection();
				}
			}
		}
	};

	class SerializationVisitorUniqueImpl
	{
	public:
		template<typename T, typename = std::enable_if<std::is_enum_v<T>, bool>::type>
		static void EnumSave(OutputArchivePtr archive, std::string_view id, T* data)
		{
			std::string name = magic_enum::enum_name(*data).data();
			SerializationVisitor<std::string>::Save(archive, id, &name);
		}

		template<typename T, typename = std::enable_if<std::is_enum_v<T>, bool>::type>
		static void EnumLoad(InputArchivePtr archive, std::string_view id, T* data)
		{
			std::string name;
			SerializationVisitor<std::string>::Load(archive, id, &name);
			*data = magic_enum::enum_cast<T>(name).value();
		}
	};

	class SerializationVisitorUtils
	{
	public:
		template<typename T> struct is_shared_ptr : std::false_type {};
		template<typename T> struct is_shared_ptr<std::shared_ptr<T>> : std::true_type {};

		template<typename T>
		static bool IsSharedPtr()
		{
			return is_shared_ptr<T>::value;
		}

		template<typename T>
		static std::string GetValueStringForContainer()
		{
			return IsSharedPtr<T>() ? "" : "value";
		}
	};
}

#endif // _SERIALIAZTION_VISITOR_HEADER_
