﻿#ifndef _SERIALIAZTION_HEADER_
#define _SERIALIAZTION_HEADER_

#include <string>

namespace TinyEngine
{
	class IArchive;

	class ISerializable
	{
	public:
		ISerializable() = default;
		virtual ~ISerializable() = default;

	public:
		virtual void SerializationProcess(IArchive* archive) = 0;
	};

	class IArchive
	{
	public:
		IArchive() = default;
		virtual ~IArchive() = default;

	public:
		virtual const std::string& GetPath() const = 0;

		virtual bool ToSection(std::string_view id) = 0;
		virtual bool HasSection(std::string_view id) const = 0;
		virtual void EndSection() = 0;

		virtual bool ToVariable(std::string_view id) = 0;
		virtual bool HasVariable(std::string_view id) const = 0;
	};

	class BaseArchive : public IArchive
	{
	public:
		BaseArchive() = default;
		virtual ~BaseArchive() = default;

	public:
		void SetPath(std::string_view path) { _path = path; }
		const std::string& GetPath() const override { return _path; }

	private:
		std::string _path;
	};

	class OutputArchive : public BaseArchive
	{
	public:
		OutputArchive() = default;
		virtual ~OutputArchive() = default;

	public:
		virtual void Save() const = 0;

		virtual void SetBool(bool value) = 0;
		virtual void SetInt(int value) = 0;
		virtual void SetFloat(float value) = 0;
		virtual void SetString(std::string_view value) = 0;
	};

	class InputArchive : public BaseArchive
	{
	public:
		InputArchive() = default;
		virtual ~InputArchive() = default;

	public:
		virtual void Load() = 0;

		virtual bool GetBool() const = 0;
		virtual int GetInt() const = 0;
		virtual float GetFloat() const = 0;
		virtual std::string GetString() const = 0;
	};
}

#endif // _SERIALIAZTION_HEADER_