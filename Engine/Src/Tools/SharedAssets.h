#pragma once
#include <unordered_set>
#include "TShared.h"

template<typename V>
class SharedAsset : public TShared<std::string, V*>
{
	typedef std::unordered_set<std::string> KeyList;
public:
	KeyList& GetKeyList()
	{
		static std::set<std::string> returnVal;
		for (auto const& key: this->m_registry)
		{
			returnVal.insert(key.first);
		}
		return GetKeyList();
	}
};

