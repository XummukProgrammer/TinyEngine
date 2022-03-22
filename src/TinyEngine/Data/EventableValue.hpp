#ifndef _EVENTABLE_VALUE_HEADER_
#define _EVENTABLE_VALUE_HEADER_

#include <TinyEngine/Events/Publisher.hpp>

#include <string>

// Макрос для создания класса, у которого есть
// возможность сигнализировать о смене значения.
#define DECLARE_EVENTABLE_VALUE(type, name) \
	class name ## EventableValue final \
	{ \
	public: \
		using ValueChangedParametersTemplate = ValueChangedParameters<type>; \
	private: \
		DECLARE_EVENT(ValueChangedParametersTemplate, ValueChanged) \
	public: \
		name ## EventableValue() = default; \
		~name ## EventableValue() = default; \
	public: \
		void SetValue(type value) \
		{ \
			ValueChangedParametersTemplate params; \
			params.prevValue = _value; \
			params.currentValue = value; \
			_value = value; \
			OnValueChanged(params); \
		} \
		type GetValue() const { return _value; } \
	private: \
		type _value; \
	};

namespace TinyEngine
{
	// Параметры для события при смене значения.
	template<typename T>
	class ValueChangedParameters final : public EventParameters
	{
	public:
		ValueChangedParameters() = default;
		~ValueChangedParameters() = default;

	public:
		// Предыдущее значение.
		T prevValue;
		// Текущее значение.
		T currentValue;
	};

	// Объявляем классы, у которых должна быть 
	// возможность сигнализировать о смене значения.
	// Доступные типы:
	// - BoolEventableValue
	// - IntEventableValue
	// - FloatEventableValue
	// - StringEventableValue
	DECLARE_EVENTABLE_VALUE(bool, Bool)
	DECLARE_EVENTABLE_VALUE(int, Int)
	DECLARE_EVENTABLE_VALUE(float, Float)
	DECLARE_EVENTABLE_VALUE(std::string, String)
}

#endif // _EVENTABLE_VALUE_HEADER_
