#include "Serialization.hpp"

#include <TinyEngine/Data/Serialization/SerializationVisitor.hpp>

#include <TinyEngine/Data/Serialization/XmlArchive.hpp>

namespace TinyEngine
{
	void SerializationUtils::SaveRoot(OutputArchivePtr archive, ISerializablePtr serializable)
	{
		TinyEngine::SerializationVisitor<TinyEngine::ISerializable>::Save(archive, "root", serializable);
	}

	void SerializationUtils::LoadRoot(InputArchivePtr archive, ISerializablePtr serializable)
	{
		TinyEngine::SerializationVisitor<TinyEngine::ISerializable>::Load(archive, "root", serializable);
	}

	void SerializationUtils::SaveRootToFile(ArchiveFormat format, std::string_view path, ISerializablePtr serializable)
	{
		if (auto archive = CreateOutputArchive(format))
		{
			archive->SetPath(path);
			SaveRoot(archive.get(), serializable);
			archive->Save();
		}
	}

	void SerializationUtils::LoadRootFromFile(ArchiveFormat format, std::string_view path, ISerializablePtr serializable)
	{
		if (auto archive = CreateInputArchive(format))
		{
			archive->SetPath(path);
			archive->Load();
			LoadRoot(archive.get(), serializable);
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
