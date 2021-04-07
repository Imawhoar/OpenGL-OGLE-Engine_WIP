#pragma once
#include <unordered_map>

#include "TSingleton.h"

template<typename K, typename V>
class TShared : public TSingleton<TShared<K, V>>
{
protected:
	std::unordered_map<K, V> m_registry;

protected:
	virtual ~TShared() override
	{
		for (auto const& val: m_registry)
			delete val.second;
	}

public:
	V& Get(const K& key) { return m_registry[key]; }
	const V& Get(const K& key) const { return m_registry[key]; }

    void Set(const K& key, const V& val) { m_registry[key] = val; }
};