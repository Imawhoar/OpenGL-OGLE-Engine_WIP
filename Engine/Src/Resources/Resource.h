#pragma once

#include "../Tools/Template/TRegistry.h"

namespace OGLE
{
	template<typename V>
	using AssetRegistry = Template::TRegistry<std::string, V*>;
}
namespace OGLE::Resources
{
	class Resource
	{
	};
}