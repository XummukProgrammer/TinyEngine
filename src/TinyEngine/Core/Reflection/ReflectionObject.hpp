#ifndef _REFLECTION_OBJECT_HEADER_
#define _REFLECTION_OBJECT_HEADER_

#include <TinyEngine/Core/Reflection/ReflectionMember.hpp>
#include <vector>
#include <memory>
#include <functional>

namespace TinyEngine
{
	class ReflectionObject final
	{
	public:
		ReflectionObject() = default;
		~ReflectionObject() = default;

	public:
		void AddMember(std::string_view name, std::unique_ptr<IReflectionMember>&& member);
		bool HasMember(std::string_view name) const;
		IReflectionMember* GetMember(std::string_view name) const;
		void ForEachMembers(const std::function<void(IReflectionMember* member)> func);

	private:
		std::vector<std::unique_ptr<IReflectionMember>> _members;
	};
}

#endif // _REFLECTION_OBJECT_HEADER_
