#pragma once
#include "Tools/Input/InputManager.h"
namespace OGLE
{
	class PlayerObject : public ActorObject
	{
	public:
		PlayerObject(Sprite* sprite) : ActorObject(sprite) { }
	public:
		void BeginActor() override
		{

		}
		void TickActor(float deltaTime) override
		{

		}

		void InputSetupActor(Input::InputManager* manager) override
		{
			manager->Bind("moveRightward", [&](float value) { MoveRight(value); });
			manager->Bind("moveForward", [&](float value) {MoveUp(value); });
			manager->Bind("rotateBody", [&](float value) {RotateClockwise(value); });

			manager->Bind("fakeZoom", [&](float value) {Zoom(value); });
		}
	private:
		float m_moveSpeed;

		void MoveRight(float value)
		{
			m_transform.AddPosition(Vector3(0.001, 0, 0) * value);
		}
		void MoveUp(float value)
		{
			m_transform.AddPosition(Vector3(0, 0.001, 0) * value);
		}
		void RotateClockwise(float value)
		{
			m_transform.AddRotation(Vector3(0, 0, 0.001) * value);
		}
		void Zoom(float value)
		{
			m_transform.AddScale(value * 0.0001, value * 0.0001, value * 0.0001);
		}
	};
}
