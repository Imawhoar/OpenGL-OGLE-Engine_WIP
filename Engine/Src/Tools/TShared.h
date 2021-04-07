#pragma once
#include <unordered_map>

#include "TSingleton.h"

template<typename K, typename V>
class TShared : public TSingleton<TShared<K, V>>
{
protected:
	float x;
	std::unordered_map<K, V> m_registry;
public:
	V& Get(const K& key) { return m_registry[key]; }
	const V& Get(const K& key) const { return m_registry[key]; }

	virtual void Set(const K& key, const V& val) const { m_registry[key] = val; }
};