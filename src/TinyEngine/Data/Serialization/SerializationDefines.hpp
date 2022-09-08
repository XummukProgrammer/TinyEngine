#ifndef _SERIALIAZTION_DEFINES_HEADER_
#define _SERIALIAZTION_DEFINES_HEADER_

#include <TinyEngine/Data/Serialization/Serialization.hpp>
#include <TinyEngine/Data/Serialization/SerializationVisitor.hpp>
#include <TinyEngine/Data/Serialization/XmlArchive.hpp>

#define TINY_ENGINE_SER_BEGIN(cls) \
	TINY_ENGINE_META_CLASS_BASE(cls) \
	public: void SerializationProcess(TinyEngine::IArchivePtr archive) override { const bool isSave = dynamic_cast<TinyEngine::OutputArchivePtr>(archive);
#define TINY_ENGINE_SER_BEGIN_DERIVED(cls, parent) \
	TINY_ENGINE_META_CLASS_BASE(cls) \
	public: void SerializationProcess(TinyEngine::IArchivePtr archive) override { \
	parent::SerializationProcess(archive); \
	const bool isSave = dynamic_cast<TinyEngine::OutputArchivePtr>(archive);
#define TINY_ENGINE_SER_END } private:
#define TINY_ENGINE_SER_FIELD_TMP(field, method, cls, type) TinyEngine::SerializationVisitor<type>::method(static_cast<cls*>(archive), #field, &field);
#define TINY_ENGINE_SER_FIELD(field) if (isSave) { TINY_ENGINE_SER_FIELD_TMP(field, Save, TinyEngine::OutputArchive, decltype(field)) } else { TINY_ENGINE_SER_FIELD_TMP(field, Load, TinyEngine::InputArchive, decltype(field)) }

#endif // _SERIALIAZTION_DEFINES_HEADER_
