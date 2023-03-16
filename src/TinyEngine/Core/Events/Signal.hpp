#ifndef _SIGNAL_HEADER_
#define _SIGNAL_HEADER_

#include <TinyEngine/Core/Events/Slot.hpp>

#include <list>
#include <memory>

namespace TinyEngine
{
	template<typename ... Args>
	class Signal final
	{
	public:
		using Slot_t = Slot<Args...>;
		using SlotPtr = std::shared_ptr<Slot_t>;
		using SlotList = std::list<SlotPtr>;

	public:
		Signal() = default;
		~Signal() = default;

	public:
		static SlotPtr MakeSlot(const typename Slot_t::Callback& callback)
		{
			return std::make_shared<Slot_t>(callback);
		}

	public:
		void Connect(SlotPtr slot);
		void Disconnect(SlotPtr slot);

		void Emit(Args ... args);

	private:
		SlotList _slots;
	};

	template<typename ... Args>
	void Signal<Args...>::Connect(SlotPtr slot)
	{
		_slots.push_back(slot);
	}

	template<typename ...Args>
	void Signal<Args...>::Disconnect(SlotPtr slot)
	{
		auto it = std::find_if(_slots.begin(), _slots.end(), [slot](SlotPtr conSlot)
		{
			return slot == conSlot;
		});
	}

	template<typename ...Args>
	void Signal<Args...>::Emit(Args ... args)
	{
		for (const auto& slot : _slots)
		{
			slot->Call(std::forward<Args>(args)...);
		}
	}
}

#endif // _SIGNAL_HEADER_
