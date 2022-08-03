#ifndef _SERIALIAZTION_VISITOR_HEADER_
#define _SERIALIAZTION_VISITOR_HEADER_

#include <TinyEngine/Data/Serialization/Serialization.hpp>

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
		static void Save(OutputArchive* archive, std::string_view id, T* data) 
		{
			if (std::is_base_of_v<ISerializable, T>)
			{
				SerializationVisitor<ISerializable>::Save(archive, id, data);
			}
		}

		static void Load(InputArchive* archive, std::string_view id, T* data) 
		{
			if (std::is_base_of_v<ISerializable, T>)
			{
				SerializationVisitor<ISerializable>::Load(archive, id, data);
			}
		}
	};

	template<>
	class SerializationVisitor<int>
	{
	public:
		static void Save(OutputArchive* archive, std::string_view id, int* data) 
		{
			archive->ToVariable(id);
			archive->SetInt(*data);
		}

		static void Load(InputArchive* archive, std::string_view id, int* data) 
		{
			archive->ToVariable(id);
			*data = archive->GetInt();
		}
	};

	template<>
	class SerializationVisitor<float>
	{
	public:
		static void Save(OutputArchive* archive, std::string_view id, float* data) 
		{
			archive->ToVariable(id);
			archive->SetFloat(*data);
		}

		static void Load(InputArchive* archive, std::string_view id, float* data) 
		{
			archive->ToVariable(id);
			*data = archive->GetFloat();
		}
	};

	template<>
	class SerializationVisitor<std::string>
	{
	public:
		static void Save(OutputArchive* archive, std::string_view id, std::string* data) 
		{
			archive->ToVariable(id);
			archive->SetString(*data);
		}

		static void Load(InputArchive* archive, std::string_view id, std::string* data) 
		{
			archive->ToVariable(id);
			*data = archive->GetString();
		}
	};

	template<>
	class SerializationVisitor<ISerializable>
	{
	public:
		static void Save(OutputArchive* archive, std::string_view id, ISerializable* data) 
		{
			if (archive->ToSection(id))
			{
				data->SerializationProcess(archive);
				archive->EndSection();
			}
		}

		static void Load(InputArchive* archive, std::string_view id, ISerializable* data) 
		{
			if (archive->ToSection(id))
			{
				data->SerializationProcess(archive);
				archive->EndSection();
			}
		}
	};

	template<typename T>
	class SerializationVisitor<std::vector<T>>
	{
	public:
		static void Save(OutputArchive* archive, std::string_view id, std::vector<T>* data) 
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

		static void Load(InputArchive* archive, std::string_view id, std::vector<T>* data) 
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
		static void Save(OutputArchive* archive, std::string_view id, std::map<K, V>* data) 
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

		static void Load(InputArchive* archive, std::string_view id, std::map<K, V>* data) 
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
		static void Save(OutputArchive* archive, std::string_view id, std::shared_ptr<T>* data) 
		{
			if (archive->ToSection(id))
			{
				if (archive->ToItem("pointer"))
				{
					auto rawPointer = data->get();

					std::string type = rawPointer->GetName();
					SerializationVisitor<std::string>::Save(archive, "type", &type);

					SerializationVisitor<T>::Save(archive, "object", rawPointer);

					archive->EndItem();
				}

				archive->EndSection();
			}
		}

		static void Load(InputArchive* archive, std::string_view id, std::shared_ptr<T>* data) 
		{
			if (archive->ToSection(id))
			{
				if (archive->ToItem("pointer"))
				{
					std::string type;
					SerializationVisitor<std::string>::Load(archive, "type", &type);

					if (*data = Factory::GetInstance().Create<T>(type))
					{
						auto rawPointer = data->get();
						
						SerializationVisitor<ISerializable>::Load(archive, "object", (ISerializable*)rawPointer);
					}

					archive->EndItem();
				}

				archive->EndSection();
			}
		}
	};
}

#define TINY_ENGINE_SER_BEGIN(cls) \
	TINY_ENGINE_META(cls) \
	public: void SerializationProcess(TinyEngine::IArchive* archive) override { const bool isSave = dynamic_cast<TinyEngine::OutputArchive*>(archive);
#define TINY_ENGINE_SER_BEGIN_DERIVED(cls, parent) \
	TINY_ENGINE_META(cls) \
	public: void SerializationProcess(TinyEngine::IArchive* archive) override { \
	parent::SerializationProcess(archive); \
	const bool isSave = dynamic_cast<TinyEngine::OutputArchive*>(archive);
#define TINY_ENGINE_SER_END } private:
#define TINY_ENGINE_SER_FIELD_TMP(field, method, cls, type) TinyEngine::SerializationVisitor<type>::method(static_cast<cls*>(archive), #field, &field);
#define TINY_ENGINE_SER_FIELD(field) if (isSave) { TINY_ENGINE_SER_FIELD_TMP(field, Save, TinyEngine::OutputArchive, decltype(field)) } else { TINY_ENGINE_SER_FIELD_TMP(field, Load, TinyEngine::InputArchive, decltype(field)) }

#endif // _SERIALIAZTION_VISITOR_HEADER_
