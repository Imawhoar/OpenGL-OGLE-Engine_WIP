#pragma once
#include "ActorBase.h"
namespace OGLE
{
	class PlayerObject : public ActorBase
	{
	public:
		PlayerObject() : ActorBase()
		{

		}
	public:
		void BeginActor() override
		{

		}
		void TickActor(float deltaTime) override
		{

		}


	private:
		float m_moveSpeed = 2.0f;
		float m_rotateSpeed = 1.0f;

		void MoveRight(float value)
		{
		}
		void MoveUp(float value)
		{
		}

	};
}
