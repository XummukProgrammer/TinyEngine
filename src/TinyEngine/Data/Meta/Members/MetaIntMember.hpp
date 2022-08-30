#ifndef _INT_PROPERTY_HEADER_
#define _INT_PROPERTY_HEADER_

#include <TinyEngine/Data/Meta/Members/IMetaMember.hpp>

namespace TinyEngine
{
	class MetaIntMemberWrapper : public IMetaMember
	{
	public:
		MetaIntMemberWrapper(std::string_view name, std::string_view description, int& value);
		virtual ~MetaIntMemberWrapper() = default;

	public:
		void LoadFromArchive(InputArchivePtr archive) override;
		void SaveToArchive(OutputArchivePtr archive) override;

		void GuiDraw(IRenderWindowSharedPtr window) override;

	private:
		int& _value;
	};

	class MetaIntMember final : public MetaIntMemberWrapper
	{
	public:
		MetaIntMember(std::string_view name, std::string_view description);
		~MetaIntMember() = default;

	public:
		void SetValue(int value) { _value = value; }
		int GetValue() const { return _value; }

	private:
		int _value = 0;
	};
}

#endif // _INT_PROPERTY_HEADER_
