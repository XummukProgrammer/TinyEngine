#ifndef _I_REFLECTION_MEMBER_HEADER_
#define _I_REFLECTION_MEMBER_HEADER_

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
}

#endif // _I_REFLECTION_MEMBER_HEADER_
