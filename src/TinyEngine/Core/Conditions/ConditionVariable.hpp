#ifndef _CONDITION_VARIABLE_HEADER_
#define _CONDITION_VARIABLE_HEADER_

#include <TinyEngine/Core/Data/Meta/MetaDefines.hpp>

#include <string>

namespace TinyEngine
{
	class ConditionContextVariable;

	class BaseConditionVariable : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(BaseConditionVariable)
		{
		}
		TINY_ENGINE_META_CLASS_END

	public:
		BaseConditionVariable() = default;
		virtual ~BaseConditionVariable() = default;

	public:
		virtual bool IsEqual(BaseConditionVariable* variable) const = 0;
		virtual bool IsLess(BaseConditionVariable* variable) const = 0;
		virtual bool IsLessOrEqual(BaseConditionVariable* variable) const = 0;
		virtual bool IsMore(BaseConditionVariable* variable) const = 0;
		virtual bool IsMoreOrEqual(BaseConditionVariable* variable) const = 0;

		virtual bool IsUnifiedType(BaseConditionVariable* variable) const = 0;

	public:
		void SetLocalContext(ConditionContextPtr context);
		ConditionContextPtr GetLocalContext() const;

	private:
		ConditionContextPtr _localContext = nullptr;
	};

	template<typename T, const char* Name>
	class ConditionVariable final : public BaseConditionVariable
	{
		using Origin = ConditionVariable<T, Name>;

		TINY_ENGINE_META_CLASS_BASE_DERIVED_BEGIN(Origin, BaseConditionVariable, Name)
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
		bool IsEqual(BaseConditionVariable* variable) const override;
		bool IsLess(BaseConditionVariable* variable) const override;
		bool IsLessOrEqual(BaseConditionVariable* variable) const override;
		bool IsMore(BaseConditionVariable* variable) const override;
		bool IsMoreOrEqual(BaseConditionVariable* variable) const override;

		bool IsUnifiedType(BaseConditionVariable* variable) const override;

	private:
		ConditionVariable<T, Name>* CastToCurrentType(BaseConditionVariable* variable) const;

	private:
		T _value { 0 };
	};

	// TODO: Для float нельзя делать обычные сравнения!

	template<typename T, const char* Name>
	bool ConditionVariable<T, Name>::IsEqual(BaseConditionVariable* variable) const
	{
		if (auto castedVariable = CastToCurrentType(variable))
		{
			return _value == castedVariable->GetValue();
		}
		return false;
	}

	template<typename T, const char* Name>
	bool ConditionVariable<T, Name>::IsLess(BaseConditionVariable* variable) const
	{
		if (auto castedVariable = CastToCurrentType(variable))
		{
			return _value < castedVariable->GetValue();
		}
		return false;
	}

	template<typename T, const char* Name>
	bool ConditionVariable<T, Name>::IsLessOrEqual(BaseConditionVariable* variable) const
	{
		if (auto castedVariable = CastToCurrentType(variable))
		{
			return _value <= castedVariable->GetValue();
		}
		return false;
	}

	template<typename T, const char* Name>
	bool ConditionVariable<T, Name>::IsMore(BaseConditionVariable* variable) const
	{
		if (auto castedVariable = CastToCurrentType(variable))
		{
			return _value > castedVariable->GetValue();
		}
		return false;
	}

	template<typename T, const char* Name>
	bool ConditionVariable<T, Name>::IsMoreOrEqual(BaseConditionVariable* variable) const
	{
		if (auto castedVariable = CastToCurrentType(variable))
		{
			return _value >= castedVariable->GetValue();
		}
		return false;
	}

	template<typename T, const char* Name>
	bool ConditionVariable<T, Name>::IsUnifiedType(BaseConditionVariable* variable) const
	{
		return CastToCurrentType(variable) != nullptr;
	}

	template<typename T, const char* Name>
	ConditionVariable<T, Name>* ConditionVariable<T, Name>::CastToCurrentType(BaseConditionVariable* variable) const
	{
		BaseConditionVariable* inputVariable = variable;
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

	class ConditionContextVariable final : public BaseConditionVariable
	{
		TINY_ENGINE_META_CLASS_DERIVED_BEGIN(ConditionContextVariable, BaseConditionVariable)
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
		BaseConditionVariableSharedPtr GetVariable() const;

	public:
		bool IsEqual(BaseConditionVariable* variable) const override;
		bool IsLess(BaseConditionVariable* variable) const override;
		bool IsLessOrEqual(BaseConditionVariable* variable) const override;
		bool IsMore(BaseConditionVariable* variable) const override;
		bool IsMoreOrEqual(BaseConditionVariable* variable) const override;

		bool IsUnifiedType(BaseConditionVariable* variable) const override;

	public:
		std::string _contextVariableId;
		bool _isGlobalContext = false;
		mutable BaseConditionVariableSharedPtr _cashedContextVariable;
	};
}

#endif // _CONDITION_VARIABLE_HEADER_
