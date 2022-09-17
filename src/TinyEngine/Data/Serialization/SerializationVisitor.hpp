#ifndef _SERIALIAZTION_VISITOR_HEADER_
#define _SERIALIAZTION_VISITOR_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Data/Serialization/Serialization.hpp>
#include <TinyEngine/Data/Factory.hpp>
#include <TinyEngine/Data/Meta/Class/MetaClass.hpp>

#include <magic_enum.hpp>

#include <string>
#include <vector>
#include <map>
#include <memory>

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
			if (archive->ToSection(id))
			{
				data->GetMembers().SaveToArchive(archive);
				archive->EndSection();
			}
		}

		static void Load(InputArchivePtr archive, std::string_view id, MetaClassPtr data) 
		{
			if (archive->ToSection(id))
			{
				data->GetMembers().LoadFromArchive(archive);
				archive->EndSection();
			}
		}
	};

	template<typename T>
	class SerializationVisitor<std::vector<T>>
	{
	public:
		static void Save(OutputArchivePtr archive, std::string_view id, std::vector<T>* data) 
		{
			if (archive->ToArray(id))
			{
				auto& dataRef = *data;

				for (auto& dataElement : dataRef)
				{
					if (archive->ToItem("element"))
					{
						SerializationVisitor<T>::Save(archive, "value", &dataElement);

						archive->EndItem();
					}
				}

				archive->EndArray();
			}
		}

		static void Load(InputArchivePtr archive, std::string_view id, std::vector<T>* data) 
		{
			if (archive->ToArray(id))
			{
				if (archive->ToItem("element"))
				{
					auto& dataRef = *data;

					do
					{
						T value;
						SerializationVisitor<T>::Load(archive, "value", &value);
						dataRef.push_back(value);
					}
					while (archive->ToNextItem("element"));

					archive->EndItem();
				}

				archive->EndArray();
			}
		}
	};

	template<typename K, typename V>
	class SerializationVisitor<std::map<K, V>>
	{
	public:
		static void Save(OutputArchivePtr archive, std::string_view id, std::map<K, V>* data) 
		{
			if (archive->ToArray(id))
			{
				auto& dataRef = *data;

				for (auto& [ dataKey, dataElement ] : dataRef)
				{
					if (archive->ToItem("pair"))
					{
						auto key = dataKey;
						SerializationVisitor<K>::Save(archive, "key", &key);
						SerializationVisitor<V>::Save(archive, "value", &dataElement);

						archive->EndItem();
					}
				}

				archive->EndArray();
			}
		}

		static void Load(InputArchivePtr archive, std::string_view id, std::map<K, V>* data) 
		{
			if (archive->ToArray(id))
			{
				if (archive->ToItem("pair"))
				{
					auto& dataRef = *data;

					do
					{
						K key;
						V value;
						SerializationVisitor<K>::Load(archive, "key", &key);
						SerializationVisitor<V>::Load(archive, "value", &value);
						dataRef[key] = value;
					}
					while (archive->ToNextItem("pair"));

					archive->EndItem();
				}

				archive->EndArray();
			}
		}
	};

	template<typename T>
	class SerializationVisitor<std::shared_ptr<T>>
	{
	public:
		static void Save(OutputArchivePtr archive, std::string_view id, std::shared_ptr<T>* data) 
		{
			if (archive->ToSection(id))
			{
				if (archive->ToItem("pointer"))
				{
					auto rawPointer = data->get();

					std::string type = rawPointer->GetClassName();
					SerializationVisitor<std::string>::Save(archive, "type", &type);

					SerializationVisitor<T>::Save(archive, "object", rawPointer);

					archive->EndItem();
				}

				archive->EndSection();
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
						
						SerializationVisitor<T>::Load(archive, "object", rawPointer);
					}

					archive->EndItem();
				}

				archive->EndSection();
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
			std::string name = magic_enum::enum_name(*data).data();
			SerializationVisitor<std::string>::Load(archive, id, &name);
			*data = magic_enum::enum_cast<T>(name).value();
		}
	};
}

#endif // _SERIALIAZTION_VISITOR_HEADER_
