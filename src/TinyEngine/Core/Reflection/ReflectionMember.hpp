#ifndef _REFLECTION_MEMBER_HEADER_
#define _REFLECTION_MEMBER_HEADER_

#include <TinyEngine/Core/Serialization/IArchive.hpp>

namespace TinyEngine
{
	class IReflectionMember
	{
	public:
		IReflectionMember() = default;
		virtual ~IReflectionMember() = default;

	public:
		virtual void SetName(std::string_view name) = 0;
		virtual const std::string& GetName() const = 0;

		virtual void Serialize(IOutputArchive* archive) = 0;
		virtual void Deserialize(IInputArchive* archive) = 0;
	};

	template<typename T>
	class ReflectionMember final : public IReflectionMember
	{
	public:
		ReflectionMember() = default;
		~ReflectionMember() = default;

	public:
		void SetName(std::string_view name) override { _name = name; }
		const std::string& GetName() const override { return _name; }

		void Serialize(IOutputArchive* archive) override;
		void Deserialize(IInputArchive* archive) override;

	public:
		void SetValue(T& value) { _value = &value; }
		const T& GetValue() const { return *_value; }
		T& GetRefValue() { return *_value; }

	private:
		std::string _name;
		T* _value;
	};

	template<typename T>
	inline void ReflectionMember<T>::Serialize(IOutputArchive* archive)
	{
	}

	template<typename T>
	inline void ReflectionMember<T>::Deserialize(IInputArchive* archive)
	{
	}
}

#endif // _REFLECTION_MEMBER_HEADER_
