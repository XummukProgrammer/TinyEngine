#ifndef _CONDITION_VARIABLE_HEADER_
#define _CONDITION_VARIABLE_HEADER_

#include <TinyEngine/Core/Data/Meta/MetaDefines.hpp>

#include <string>

namespace TinyEngine
{
	class ConditionContextVariable;

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

	template<typename T, const char* Name>
	class ConditionVariable final : public IConditionVariable
	{
		using Origin = ConditionVariable<T, Name>;

		TINY_ENGINE_META_CLASS_BASE_DERIVED_BEGIN(Origin, IConditionVariable, Name)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_value, "Value", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		ConditionVariable() = default;
		~ConditionVariable() = default;

	public:
		void SetValue(T value) { _value = value; }
		T GetValue() const { return _value; }

	public:
		bool IsEqual(IConditionVariable* variable) const override;
		bool IsLess(IConditionVariable* variable) const override;
		bool IsLessOrEqual(IConditionVariable* variable) const override;
		bool IsMore(IConditionVariable* variable) const override;
		bool IsMoreOrEqual(IConditionVariable* variable) const override;

		bool IsUnifiedType(IConditionVariable* variable) const override;

	private:
		ConditionVariable<T, Name>* CastToCurrentType(IConditionVariable* variable) const;

	private:
		T _value { 0 };
	};

	// TODO: Для float нельзя делать обычные сравнения!

	template<typename T, const char* Name>
	bool ConditionVariable<T, Name>::IsEqual(IConditionVariable* variable) const
	{
		if (auto castedVariable = CastToCurrentType(variable))
		{
			return _value == castedVariable->GetValue();
		}
		return false;
	}

	template<typename T, const char* Name>
	bool ConditionVariable<T, Name>::IsLess(IConditionVariable* variable) const
	{
		if (auto castedVariable = CastToCurrentType(variable))
		{
			return _value < castedVariable->GetValue();
		}
		return false;
	}

	template<typename T, const char* Name>
	bool ConditionVariable<T, Name>::IsLessOrEqual(IConditionVariable* variable) const
	{
		if (auto castedVariable = CastToCurrentType(variable))
		{
			return _value <= castedVariable->GetValue();
		}
		return false;
	}

	template<typename T, const char* Name>
	bool ConditionVariable<T, Name>::IsMore(IConditionVariable* variable) const
	{
		if (auto castedVariable = CastToCurrentType(variable))
		{
			return _value > castedVariable->GetValue();
		}
		return false;
	}

	template<typename T, const char* Name>
	bool ConditionVariable<T, Name>::IsMoreOrEqual(IConditionVariable* variable) const
	{
		if (auto castedVariable = CastToCurrentType(variable))
		{
			return _value >= castedVariable->GetValue();
		}
		return false;
	}

	template<typename T, const char* Name>
	bool ConditionVariable<T, Name>::IsUnifiedType(IConditionVariable* variable) const
	{
		return CastToCurrentType(variable) != nullptr;
	}

	template<typename T, const char* Name>
	ConditionVariable<T, Name>* ConditionVariable<T, Name>::CastToCurrentType(IConditionVariable* variable) const
	{
		IConditionVariable* inputVariable = variable;
		if (auto contextVariable = dynamic_cast<ConditionContextVariable*>(variable))
		{
			inputVariable = contextVariable->GetVariable().get();
		}
		return dynamic_cast<ConditionVariable<T, Name>*>(inputVariable);
	}

	static const char conditionIntVariableString[] = "ConditionIntVariable";
	using ConditionIntVariable = ConditionVariable<int, conditionIntVariableString>;

	static const char conditionFloatVariableString[] = "ConditionFloatVariable";
	using ConditionFloatVariable = ConditionVariable<float, conditionFloatVariableString>;

	static const char conditionStringVariableString[] = "ConditionStringVariable";
	using ConditionStringVariable = ConditionVariable<std::string, conditionStringVariableString>;

	class ConditionContextVariable final : public IConditionVariable
	{
		TINY_ENGINE_META_CLASS_DERIVED_BEGIN(ConditionContextVariable, IConditionVariable)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_contextVariableId, "ContextVariableID", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_isGlobalContext, "IsGlobalContext", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		ConditionContextVariable() = default;
		~ConditionContextVariable() = default;

	public:
		const std::string& GetContextVariableId() const { return _contextVariableId; }
		IConditionVariableSharedPtr GetVariable() const;

	public:
		bool IsEqual(IConditionVariable* variable) const override;
		bool IsLess(IConditionVariable* variable) const override;
		bool IsLessOrEqual(IConditionVariable* variable) const override;
		bool IsMore(IConditionVariable* variable) const override;
		bool IsMoreOrEqual(IConditionVariable* variable) const override;

		bool IsUnifiedType(IConditionVariable* variable) const override;

	public:
		std::string _contextVariableId;
		bool _isGlobalContext = false;
		mutable IConditionVariableSharedPtr _cashedContextVariable;
	};
}

#endif // _CONDITION_VARIABLE_HEADER_
