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
		static void Save(OutputArchive* archive, std::string_view id, T* data) {}
		static void Load(InputArchive* archive, std::string_view id, T* data) {}
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
}

#define TINY_ENGINE_SER_BEGIN public: void SerializationProcess(TinyEngine::IArchive* archive) override { const bool isSave = static_cast<TinyEngine::OutputArchive*>(archive);
#define TINY_ENGINE_SER_END } private:
#define TINY_ENGINE_SER_FIELD(field) if (isSave) { TinyEngine::SerializationVisitor<decltype(field)>::Save(static_cast<TinyEngine::OutputArchive*>(archive), #field, &field); } else { TinyEngine::SerializationVisitor<decltype(field)>::Load(static_cast<TinyEngine::InputArchive*>(archive), #field, &field); }

#endif // _SERIALIAZTION_VISITOR_HEADER_
