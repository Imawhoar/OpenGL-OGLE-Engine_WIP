#pragma once
#include "glm/gtc/quaternion.hpp"
#include "Vector.h"
#include "Matrix.h"

namespace OGLE
{
	class Quaternion
	{
	public:
		Quaternion() : m_quat() {}
		Quaternion(float x, float y, float z, float w) : m_quat(x, y, z, w) {}
		Quaternion(const Vector3& euler) : m_quat(euler) {}
		Quaternion(const Matrix3& matrix) : m_quat(matrix) {}
		Quaternion(const Vector4& matrix) : m_quat(matrix) {}
	public:

		void Normalize() { m_quat = normalize(m_quat); }

		
		[[nodiscard]] auto ToEuler() const { return eulerAngles(m_quat); }
		
		[[nodiscard]] auto ToMat4()  const { return mat4_cast(m_quat); }
		[[nodiscard]] auto ToMat3()  const { return mat3_cast(m_quat); }
		
		[[nodiscard]] auto Yaw()     const { return yaw(m_quat); }
		[[nodiscard]] auto Pitch()   const { return pitch(m_quat); }
		[[nodiscard]] auto Roll()    const { return roll(m_quat); }
		
		[[nodiscard]] auto GetComponents() const { return Vector4(m_quat.x, m_quat.y, m_quat.z, m_quat.w); }
		[[nodiscard]] auto& GetQuat() const   { return m_quat; }
		
		[[nodiscard]] auto GetX() const { return m_quat.x; }
		[[nodiscard]] auto GetY() const { return m_quat.y; }
		[[nodiscard]] auto GetZ() const { return m_quat.z; }
		[[nodiscard]] auto GetW() const { return m_quat.w; }


	private:
		glm::quat m_quat;
		friend class Transform;
	};
}
