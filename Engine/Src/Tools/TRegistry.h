#pragma once
#include <unordered_map>
#include "../Resources/Resource.h"

#include "TSingleton.h"

template<typename K, typename V>
class TRegistry;

template<typename V>
using AssetRegistry = TRegistry<std::string, V>;

template<typename V>
using ResourceRegistry = TRegistry<std::string, Resource>;

template<typename K, typename V>
class TRegistry final : public TSingleton<TRegistry<K, V>>
{
protected:
	std::unordered_map<K, V> m_registry;

public:
	virtual ~TRegistry() override			{ m_registry.erase(m_registry.begin(), m_registry.end()); }
										    
	V& Get(const K& key)			        { return m_registry[key]; }
	const V& Get(const K& key) const	    { return m_registry[key]; }

	void Insert(const K& key, const V& val) { m_registry[key] = val; }
};
