#include "Serialization.hpp"

#include <TinyEngine/Data/Serialization/SerializationVisitor.hpp>

#include <TinyEngine/Data/Serialization/XmlArchive.hpp>

namespace TinyEngine
{
	void SerializationUtils::SaveRoot(OutputArchive* archive, ISerializable* serializable)
	{
		TinyEngine::SerializationVisitor<TinyEngine::ISerializable>::Save(archive, "root", serializable);
	}

	void SerializationUtils::LoadRoot(InputArchive* archive, ISerializable* serializable)
	{
		TinyEngine::SerializationVisitor<TinyEngine::ISerializable>::Load(archive, "root", serializable);
	}

	void SerializationUtils::SaveRootToFile(ArchiveFormat format, std::string_view path, ISerializable* serializable)
	{
		if (auto archive = CreateOutputArchive(format))
		{
			archive->SetPath(path);
			SaveRoot(archive.get(), serializable);
			archive->Save();
		}
	}

	void SerializationUtils::LoadRootFromFile(ArchiveFormat format, std::string_view path, ISerializable* serializable)
	{
		if (auto archive = CreateInputArchive(format))
		{
			archive->SetPath(path);
			archive->Load();
			LoadRoot(archive.get(), serializable);
		}
	}

	std::unique_ptr<OutputArchive> SerializationUtils::CreateOutputArchive(ArchiveFormat format)
	{
		switch (format)
		{
		case ArchiveFormat::Xml:
			return std::make_unique<XmlOutputArchive>();
		}
		return nullptr;
	}

	std::unique_ptr<InputArchive> SerializationUtils::CreateInputArchive(ArchiveFormat format)
	{
		switch (format)
		{
		case ArchiveFormat::Xml:
			return std::make_unique<XmlInputArchive>();
		}
		return nullptr;
	}
}
