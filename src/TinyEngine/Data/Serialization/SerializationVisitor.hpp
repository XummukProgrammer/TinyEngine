#ifndef _SERIALIAZTION_VISITOR_HEADER_
#define _SERIALIAZTION_VISITOR_HEADER_

#include <TinyEngine/Data/Serialization/Serialization.hpp>

#include <string>

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
}

#define TINY_ENGINE_SER_BEGIN public: void SerializationProcess(TinyEngine::IArchive* archive) override { const bool isSave = dynamic_cast<TinyEngine::OutputArchive*>(archive);
#define TINY_ENGINE_SER_END } private:
#define TINY_ENGINE_SER_FIELD_TMP(field, method, cls, type) TinyEngine::SerializationVisitor<type>::method(static_cast<cls*>(archive), #field, &field);
#define TINY_ENGINE_SER_FIELD(field) if (isSave) { TINY_ENGINE_SER_FIELD_TMP(field, Save, TinyEngine::OutputArchive, decltype(field)) } else { TINY_ENGINE_SER_FIELD_TMP(field, Load, TinyEngine::InputArchive, decltype(field)) }

#endif // _SERIALIAZTION_VISITOR_HEADER_
