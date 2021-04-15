#pragma once

#include <glm/detail/type_quat.hpp>
#include "Utils/Vector.h"
#include "Utils/Quaternion.h"
namespace OGLE
{
	class Transform {
		Vector3 m_position{};
		Vector3 m_scale{};
		Vector3 m_rotation{};
		Quaternion m_quaternion{};
	public:
		Transform() {
			m_position = {};
			m_scale = Vector3(1, 1, 1);
			m_rotation = {};
		}

	public:
		[[nodiscard]] const auto& GetPosition() const { return m_position; }
		void SetPosition(const Vector3& pos) { m_position = pos; }
		void AddPosition(const Vector3& deltaPos) { m_position += deltaPos; }

		[[nodiscard]] const auto& GetScale() const { return m_scale; }
		void SetScale(const Vector3& scale) { m_scale = scale; }
		void SetScale(float x, float y, float z) { m_scale = Vector3(x,y,z); }
		
		void AddScale(const Vector3& deltaScale) { m_scale += deltaScale; }
		void AddScale(float deltaX, float deltaY, float deltaZ) { m_scale += Vector3(deltaX, deltaY, deltaZ); }

		[[nodiscard]] const auto& GetRotation() const { return m_rotation;  }
		[[nodiscard]] const auto& GetQuaternion() const { return m_quaternion;  }
		
		void SetRotation(const Vector3& rot)
		{
			m_rotation = rot;
			m_quaternion.m_quat = glm::quat(m_rotation);
		}

		//TODO: The rotation has to be inverted for some reason or it will move the opposite of give angle.
		//Probably the camera orientation
		void AddRotation(const Vector3& deltaRot)
		{
			m_rotation -= deltaRot;
			m_quaternion.m_quat = glm::quat(m_rotation);
		}
		void AddRotation(float x, float y, float z)
		{
			m_rotation -= Vector3(x,y,z);
			m_quaternion.m_quat = glm::quat(m_rotation);
		}

		//TODO: Should probably not be static since we actually want per instance. Leave as if for now.
		[[nodiscard]] static auto GetRight() { return Vector3(1, 0, 0); }
		[[nodiscard]] static auto GetUp()    { return Vector3(0, 1, 0); }
		[[nodiscard]] static auto GetFront() { return Vector3(0, 0, 1); }

	};
}