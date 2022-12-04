#ifndef _PROPERTIES_HEADER_
#define _PROPERTIES_HEADER_

#include <TinyEngine/Core/Forwards.hpp>

#include <vector>
#include <list>
#include <string>
#include <functional>

namespace TinyEngine
{
	class MetaMemberInitializer
	{
	public:
		MetaMemberInitializer() = default;
		virtual ~MetaMemberInitializer() = default;

	public:
		virtual void OnInit() = 0;

	public:
		void SetMember(const IMetaMemberSharedPtr& member);

	protected:
		IMetaMemberSharedPtr _member;
	};

	class MetaMemberNameInitializer final : public MetaMemberInitializer
	{
	public:
		MetaMemberNameInitializer(std::string_view name) : _name(name) {}
		~MetaMemberNameInitializer() = default;

	public:
		void OnInit() override;

	private:
		std::string _name;
	};

	class MetaMemberDescriptionInitializer final : public MetaMemberInitializer
	{
	public:
		MetaMemberDescriptionInitializer(std::string_view description) : _description(description) {}
		~MetaMemberDescriptionInitializer() = default;

	public:
		void OnInit() override;

	private:
		std::string _description;
	};

	class MetaMemberSaveFlagInitializer final : public MetaMemberInitializer
	{
	public:
		MetaMemberSaveFlagInitializer() = default;
		~MetaMemberSaveFlagInitializer() = default;

	public:
		void OnInit() override;
	};

	class MetaMemberLoadFlagInitializer final : public MetaMemberInitializer
	{
	public:
		MetaMemberLoadFlagInitializer() = default;
		~MetaMemberLoadFlagInitializer() = default;

	public:
		void OnInit() override;
	};

	class MetaMemberEditorFlagInitializer final : public MetaMemberInitializer
	{
	public:
		MetaMemberEditorFlagInitializer() = default;
		~MetaMemberEditorFlagInitializer() = default;

	public:
		void OnInit() override;
	};

	class MetaMemberDefaultFlagsInitializer final : public MetaMemberInitializer
	{
	public:
		MetaMemberDefaultFlagsInitializer() = default;
		~MetaMemberDefaultFlagsInitializer() = default;

	public:
		void OnInit() override;
	};

	class MetaMembers final
	{
	public:
		using OnForEach = std::function<void(std::string_view, IMetaMemberSharedPtr)>;
		using MetaMemberInitializerSharedPtr = std::shared_ptr<MetaMemberInitializer>;
		using MemberInitializerList = std::list<MetaMemberInitializerSharedPtr>;

	public:
		MetaMembers() = default;
		~MetaMembers() = default;

	public:
		void AddMember(IMetaMemberSharedPtr member, const MemberInitializerList& initializerList);
		IMetaMemberSharedPtr GetMember(std::string_view id) const;
		bool HasMember(std::string_view id) const;

		void ForEach(const OnForEach& callback) const;

		void LoadFromArchive(InputArchivePtr archive);
		void SaveToArchive(OutputArchivePtr archive);

		void AddGuiWidgetsToContainer(GuiWidgetContainerPtr container);

		bool IsEmpty() const { return _members.empty(); }

	private:
		std::vector<std::pair<std::string, IMetaMemberSharedPtr>> _members;
	};
}

#endif // _PROPERTIES_HEADER_
