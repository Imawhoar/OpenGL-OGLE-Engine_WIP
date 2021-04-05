#include "Transform.h"

#include "glm/mat4x4.hpp"
Transform::Transform() {

	m_position = {};
	m_rotation = {};
	m_scale = glm::vec3(1);
}

#pragma region GETTER
const glm::vec3& Transform::GetPosition() const {
	return m_position;
}
glm::vec3& Transform::GetPosition() {
	return m_position;
}

const glm::vec3& Transform::GetScale() const {
	return m_scale;
}
glm::vec3& Transform::GetScale() {
	return m_scale;
}

const glm::vec3& Transform::GetRotation() const {
	return m_rotation;
}
glm::vec3& Transform::GetRotation() {
	return m_rotation;
}


glm::vec3 Transform::GetRightVector() const {
	return glm::vec3(1, 0, 0);
}
glm::vec3 Transform::GetUpVector() const {
	return glm::vec3(0, 1, 0);
}
glm::vec3 Transform::GetForwardVector() const {
	return glm::vec3(0, 0, 1);
}
#pragma endregion
#pragma region SETTER
void Transform::SetPosition(const glm::vec3& pos) {
	m_position = pos;
}
void Transform::SetRotation(const glm::vec3& rot) {
	m_rotation = rot;
}
void Transform::SetScale(const glm::vec3& scale) {
	m_scale = scale;
}
#pragma endregion
#pragma region ADDER
void Transform::AddPosition(const glm::vec3& deltaPos) {
	m_position += deltaPos;
}
void Transform::AddScale(const glm::vec3& deltaScale) {
	m_scale += deltaScale;
}
void Transform::AddRotation(const glm::vec3& deltaRot) {
	m_rotation += deltaRot;
}

