#pragma once
#include "WorldManager.h"
namespace OGLE
{
	class DefaultWorldManager : public WorldManager
	{
	public:
		void Begin() override;
		void End() override;
		void Tick(float delta) override;
	};
}
