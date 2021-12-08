#pragma once
#include <functional>

#define OGLE_EVENT(ret, ...) typedef OGLE::Template::TDelegate<ret, __VA_ARGS__>
#define OGLE_CALLBACK(...) typedef OGLE::Template::TDelegate<void, __VA_ARGS__>

namespace OGLE::Template
{
	//TODO: This might not be useful after all... Should i just delete this?
	template<typename TCaller, typename TRet, typename ...TArgs>
	struct Caller
	{
	private:

		Caller(const Caller&) = delete;
		Caller(Caller&&) = delete;
		Caller& operator=(const Caller&) = delete;

	public:
		std::function<TRet(TArgs ...)> callerFunction;
		~Caller() = default;
		Caller() = default;

		Caller(TCaller& instance, TRet(TCaller::* function)(TArgs...))
		{
			callerFunction = [&instance, function](TArgs... args) {
				return (instance.*function)(std::forward<TArgs>(args)...);
			};
		}

		void Get(float x)
		{
			callerFunction(x);
		}
	};

	template<typename TRetVal, typename... TArgs>
	class TDelegate final
	{
	private:
		std::vector<std::function<TRetVal(TArgs...)>> m_events;


	public:
		TDelegate() = default;
		~TDelegate() = default;
		TDelegate(const TDelegate<TRetVal, TArgs...>&) = delete;
	public:

		void Bind(std::function<TRetVal(TArgs...)> func)
		{
			m_events.emplace_back(func);
		}

		template<typename TCaller>
		void Bind(TCaller& caller, TRetVal(TCaller::* func)(TArgs... args))
		{
			m_events.push_back([&caller, func](TArgs... args)
				{
					(caller.*func)(args...);
				});
		}

		void Invoke(TArgs... args)
		{
			for (auto& evnt : m_events)
				evnt(args...);
		}
	};

	template<typename... TArgs>
	using TCallback = TDelegate<void, TArgs...>;
}
