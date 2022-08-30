#ifndef _INTERFACE_PROPERTY_HEADER_
#define _INTERFACE_PROPERTY_HEADER_

#include <TinyEngine/Core/Forwards.hpp>

#include <string>

namespace TinyEngine
{
	class PropertyData
	{
	public:
		PropertyData(std::string_view name, std::string_view description);
		virtual ~PropertyData() = default;

	public:
		const std::string& GetName() const { return _name; }
		const std::string& GetDescription() const { return _description; }

	private:
		std::string _name;
		std::string _description;
	};

	class IProperty : public PropertyData
	{
	public:
		IProperty(std::string_view name, std::string_view description);
		virtual ~IProperty() = default;

	public:
		virtual void LoadFromArchive(InputArchivePtr archive) = 0;
		virtual void SaveToArchive(OutputArchivePtr archive) = 0;

		virtual void GuiDraw(IRenderWindowSharedPtr window) = 0;
	};
}

#endif // _INTERFACE_PROPERTY_HEADER_
