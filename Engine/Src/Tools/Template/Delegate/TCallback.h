#pragma once
#include <functional>
#include <algorithm>

namespace OGLE::Template
{
	template<typename... TArgs>
	class TCallback
	{
	private:
		std::vector<std::function<void(TArgs...)>> m_events;

	public:
		TCallback() = default;
		virtual ~TCallback() = default;
		void operator=(TCallback<TArgs...> rhs) = delete;
		TCallback(const TCallback<TArgs...>&) = delete;
	public:

		void Bind(std::function<void(TArgs...)> func)
		{
			m_events.emplace_back(func);
		}

		//TODO: Make this actually fucking work.
		//Bonus if you neck yourself when ur done.
		template<typename TCaller>
		void Bind(TCaller* caller, void(TCaller::* func)(TArgs... args))
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
}
