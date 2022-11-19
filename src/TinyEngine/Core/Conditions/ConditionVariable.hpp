#ifndef _CONDITION_VARIABLE_HEADER_
#define _CONDITION_VARIABLE_HEADER_

#include <TinyEngine/Core/Data/Meta/MetaDefines.hpp>

#include <string>

namespace TinyEngine
{
	class IConditionVariable : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(IConditionVariable)
		{
		}
		TINY_ENGINE_META_CLASS_END

	public:
		IConditionVariable() = default;
		virtual ~IConditionVariable() = default;

	public:
		virtual bool IsEqual(IConditionVariable* variable) const = 0;
		virtual bool IsLess(IConditionVariable* variable) const = 0;
		virtual bool IsLessOrEqual(IConditionVariable* variable) const = 0;
		virtual bool IsMore(IConditionVariable* variable) const = 0;
		virtual bool IsMoreOrEqual(IConditionVariable* variable) const = 0;

		virtual bool IsUnifiedType(IConditionVariable* variable) const = 0;
	};

	template<typename T>
	class ConditionVariable final : public IConditionVariable
	{
		TINY_ENGINE_META_CLASS_DERIVED_BEGIN(ConditionVariable<T>, IConditionVariable)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_value, "Value", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		ConditionVariable() = default;
		~ConditionVariable() = default;

	public:
		T GetValue() const { return _value; }

	public:
		bool IsEqual(IConditionVariable* variable) const override;
		bool IsLess(IConditionVariable* variable) const override;
		bool IsLessOrEqual(IConditionVariable* variable) const override;
		bool IsMore(IConditionVariable* variable) const override;
		bool IsMoreOrEqual(IConditionVariable* variable) const override;

		bool IsUnifiedType(IConditionVariable* variable) const override;

	private:
		ConditionVariable<T>* CastToCurrentType(IConditionVariable* variable) const;

	private:
		T _value { 0 };
	};

	// TODO: Для float нельзя делать обычные сравнения!

	template<typename T>
	bool ConditionVariable<T>::IsEqual(IConditionVariable* variable) const
	{
		if (auto castedVariable = CastToCurrentType(variable))
		{
			return _value == castedVariable->GetValue();
		}
		return false;
	}

	template<typename T>
	bool ConditionVariable<T>::IsLess(IConditionVariable* variable) const
	{
		if (auto castedVariable = CastToCurrentType(variable))
		{
			return _value < castedVariable->GetValue();
		}
		return false;
	}

	template<typename T>
	bool ConditionVariable<T>::IsLessOrEqual(IConditionVariable* variable) const
	{
		if (auto castedVariable = CastToCurrentType(variable))
		{
			return _value <= castedVariable->GetValue();
		}
		return false;
	}

	template<typename T>
	bool ConditionVariable<T>::IsMore(IConditionVariable* variable) const
	{
		if (auto castedVariable = CastToCurrentType(variable))
		{
			return _value > castedVariable->GetValue();
		}
		return false;
	}

	template<typename T>
	bool ConditionVariable<T>::IsMoreOrEqual(IConditionVariable* variable) const
	{
		if (auto castedVariable = CastToCurrentType(variable))
		{
			return _value >= castedVariable->GetValue();
		}
		return false;
	}

	template<typename T>
	bool ConditionVariable<T>::IsUnifiedType(IConditionVariable* variable) const
	{
		return CastToCurrentType(variable) != nullptr;
	}

	template<typename T>
	ConditionVariable<T>* ConditionVariable<T>::CastToCurrentType(IConditionVariable* variable) const
	{
		return dynamic_cast<ConditionVariable<T>*>(variable);
	}

	using ConditionIntVariable = ConditionVariable<int>;
	using ConditionFloatVariable = ConditionVariable<float>;
	using ConditionStringVariable = ConditionVariable<std::string>;
}

#endif // _CONDITION_VARIABLE_HEADER_
