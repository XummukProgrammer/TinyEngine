#ifndef _INT_PROPERTY_HEADER_
#define _INT_PROPERTY_HEADER_

#include <TinyEngine/Data/Properties/IProperty.hpp>

namespace TinyEngine
{
	class IntPropertyWrapper : public IProperty
	{
	public:
		IntPropertyWrapper(std::string_view name, std::string_view description, int& value);
		virtual ~IntPropertyWrapper() = default;

	public:
		void LoadFromArchive(InputArchivePtr archive) override;
		void SaveToArchive(OutputArchivePtr archive) override;

		void GuiDraw(IRenderWindowSharedPtr window) override;

	private:
		int& _value;
	};

	class IntProperty final : public IntPropertyWrapper
	{
	public:
		IntProperty(std::string_view name, std::string_view description);
		~IntProperty() = default;

	public:
		void SetValue(int value) { _value = value; }
		int GetValue() const { return _value; }

	private:
		int _value = 0;
	};
}

#endif // _INT_PROPERTY_HEADER_
