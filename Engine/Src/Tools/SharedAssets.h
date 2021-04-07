#pragma once
#include "TShared.h"
#include <algorithm>
#include <set>

template<typename V>
class SharedAsset : public TShared<std::string, V>
{
	typedef std::set<std::string> KeyList;
public:

	void Set(const std::string& key, const V& val) const override
	{

	}
};

