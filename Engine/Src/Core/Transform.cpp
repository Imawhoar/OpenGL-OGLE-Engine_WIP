#include "Transform.h"
#include "glm/detail/type_quat.hpp"

namespace OGLE
{
	const Vector3& Transform::GetPosition() const {
		return m_position;
	}

	const Vector3& Transform::GetScale() const {
		return m_scale;
	}

	const Vector3& Transform::GetEuler() const {
		return m_eulerRotation;
	}

	const Quaternion& Transform::GetQuaternion() const {
		return m_quaternion;
	}

	Transform::Transform()
	{
		m_position = {};
		m_scale = Vector3(1, 1, 1);
		m_quaternion = {};
	}

	void Transform::SetPosition(const Vector3& position) {
		m_position = position;
	}

	void Transform::AddPosition(const Vector3& delta) {
		m_position += delta;
	}



	void Transform::SetScale(const Vector3& size) {
		m_scale = size;
	}



	void Transform::AddScale(const Vector3& delta) {
		m_scale += delta;
	}

	void Transform::SetRotation(const Vector3& eulerRotation) {
		m_eulerRotation = eulerRotation;
		m_quaternion = glm::quat(eulerRotation);
	}

	void Transform::SetRotation(const Quaternion& rotation) {
		m_eulerRotation = eulerAngles(rotation);
		m_quaternion = rotation;
	}

	void Transform::AddRotation(const Vector3& deltaEuler) {
		m_quaternion = glm::quat(deltaEuler) * m_quaternion;
	}

	void Transform::AddRotation(const Quaternion& delta) {
		m_quaternion = delta * m_quaternion;
	}


	Vector3 Transform::GetRight() {
		return Vector3(1, 0, 0);
	}

	Vector3 Transform::GetUp() {
		return Vector3(0, 1, 0);
	}

	Vector3 Transform::GetFront() {
		return Vector3(0, 0, 1);
	}


}
