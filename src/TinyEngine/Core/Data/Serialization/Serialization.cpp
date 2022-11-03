#include "Serialization.hpp"

#include <TinyEngine/Core/Data/Serialization/SerializationVisitor.hpp>
#include <TinyEngine/Core/Data/Serialization/XmlArchive.hpp>
#include <TinyEngine/Core/Data/Meta/Class/MetaClass.hpp>


namespace TinyEngine
{
	void SerializationUtils::SaveRoot(OutputArchivePtr archive, MetaClassPtr metaClass)
	{
		TinyEngine::SerializationVisitor<TinyEngine::MetaClass>::Save(archive, "root", metaClass);
	}

	void SerializationUtils::LoadRoot(InputArchivePtr archive, MetaClassPtr metaClass)
	{
		TinyEngine::SerializationVisitor<TinyEngine::MetaClass>::Load(archive, "root", metaClass);
	}

	void SerializationUtils::SaveRootToFile(ArchiveFormat format, std::string_view path, MetaClassPtr metaClass)
	{
		if (auto archive = CreateOutputArchive(format))
		{
			archive->SetPath(path);
			SaveRoot(archive.get(), metaClass);
			archive->Save();
		}
	}

	void SerializationUtils::LoadRootFromFile(ArchiveFormat format, std::string_view path, MetaClassPtr metaClass)
	{
		if (auto archive = CreateInputArchive(format))
		{
			archive->SetPath(path);
			archive->Load();
			LoadRoot(archive.get(), metaClass);
		}
	}

	OutputArchiveUniquePtr SerializationUtils::CreateOutputArchive(ArchiveFormat format)
	{
		switch (format)
		{
		case ArchiveFormat::Xml:
			return std::make_unique<XmlOutputArchive>();
		}
		return nullptr;
	}

	InputArchiveUniquePtr SerializationUtils::CreateInputArchive(ArchiveFormat format)
	{
		switch (format)
		{
		case ArchiveFormat::Xml:
			return std::make_unique<XmlInputArchive>();
		}
		return nullptr;
	}
}
