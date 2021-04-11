#pragma once


//TODO: start working on a more defined delegate/callback system
template <bool Const, typename Class, typename FuncType>
struct TFunPtrType;

template <typename Class, typename RetType, typename... ArgTypes>
struct TFunPtrType<false, Class, RetType(ArgTypes...)>
{
	typedef RetType(Class::* Type)(ArgTypes...);
};

template <typename Class, typename RetType, typename... ArgTypes>
struct TFunPtrType<true, Class, RetType(ArgTypes...)>
{
	typedef RetType(Class::* Type)(ArgTypes...) const;
};