#ifndef _STATES_HEADER_
#define _STATES_HEADER_

#include <TinyEngine/Core/Data/Meta/MetaDefines.hpp>
#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Assets/Asset.hpp>

#include <TinyEngine/Core/States/State.hpp>

#include <map>
#include <string>

namespace TinyEngine
{
	class States final : public Asset
	{
		TINY_ENGINE_META_CLASS_DERIVED_BEGIN(States, Asset)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_states, "States", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_startStateId, "StartStateID", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		States() = default;
		~States() = default;

	public:
		void OnInit();
		void OnDeinit();
		void OnUpdate();

	public:
		const std::string& GetCurrentStateId() const { return _currentStateId; }

		void ChangeState(std::string_view stateId);

	private:
		std::map<std::string, StateSharedPtr> _states;
		std::string _startStateId;
		std::string _currentStateId;
	};
}

#endif // _STATES_HEADER_
