#pragma once
#include <functional>
#include <algorithm>

template<typename TRet, typename... TArgs>
class TDelegate final
{
private:
	std::vector<std::function<TRet(TArgs...)>> m_events;

public:
	TDelegate() = default;
	virtual ~TDelegate() = default;
	void operator=(TDelegate<TRet, TArgs...> rhs) = delete;
	TDelegate(const TDelegate<TRet, TArgs...>&) = delete;
public:

	void Bind(std::function<TRet(TArgs...)> func)
	{
		m_events.emplace_back(func);
	}

	//TODO: Make this actually fucking work.
	//Bonus if you neck yourself when ur done.
	template<typename TCaller>
	void Bind(TCaller& caller, TRet(TCaller::*func)(TArgs... args))
	{
		m_events.emplace_back([&](TArgs... args)
		{
				caller.*func(args...);
		});
	}
	
	void Invoke(TArgs... args)
	{
		for (auto& evnt : m_events)
			evnt(args...);
	}
};
