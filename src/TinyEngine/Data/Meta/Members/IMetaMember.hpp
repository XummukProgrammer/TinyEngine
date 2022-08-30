#ifndef _INTERFACE_META_MEMBER_HEADER_
#define _INTERFACE_META_MEMBER_HEADER_

#include <TinyEngine/Core/Forwards.hpp>

#include <string>

namespace TinyEngine
{
	class MetaMemberData
	{
	public:
		MetaMemberData(std::string_view name, std::string_view description);
		virtual ~MetaMemberData() = default;

	public:
		const std::string& GetName() const { return _name; }
		const std::string& GetDescription() const { return _description; }

	private:
		std::string _name;
		std::string _description;
	};

	class IMetaMember : public MetaMemberData
	{
	public:
		IMetaMember(std::string_view name, std::string_view description);
		virtual ~IMetaMember() = default;

	public:
		virtual void LoadFromArchive(InputArchivePtr archive) = 0;
		virtual void SaveToArchive(OutputArchivePtr archive) = 0;

		virtual void GuiDraw(IRenderWindowSharedPtr window) = 0;
	};
}

#endif // _INTERFACE_META_MEMBER_HEADER_
