#include "Camera2D.h"


Camera2D::Camera2D(float left, float right, float bottom, float top, float near, float far) {

	m_transform.SetPosition(glm::vec3(0, 0, 10));
	m_transform.SetRotation(glm::vec3(0, 0, 0));

	m_size = 5;

	m_aspectRatio = 16.0f / 9.0f;
	SetClipInterval(near, far);

	m_left = left;
	m_right = right;
	m_bottom = bottom;
	m_top = top;

	RecalculateProjection();
	RecalculateView();
}
Camera2D::Camera2D(float near, float far) {

	m_transform.SetPosition(glm::vec3(0, 0, 10));
	m_transform.SetRotation(glm::vec3(0, 0, 0));

	m_size = 5;

	m_aspectRatio = 16.0f / 9.0f;

	m_left = -1;
	m_right = 1;
	m_bottom = -1;
	m_top = 1;

	SetClipInterval(near, far);
	m_projectionMatrix = glm::ortho(
		m_left * m_size * m_aspectRatio,
		m_right * m_size * m_aspectRatio,
		m_bottom * m_size,
		m_top * m_size,
		near, far);

	RecalculateView();
}
Camera2D::Camera2D() {

	m_transform.SetPosition(glm::vec3(0, 0, 10));
	m_transform.SetRotation(glm::vec3(0, 0, 0));

	m_size = 5;

	m_aspectRatio = 16.0f / 9.0f;

	m_left = -1;
	m_right = 1;
	m_bottom = -1;
	m_top = 1;

	SetClipInterval(0.0001f, 1000.0f);
	m_projectionMatrix = glm::ortho(
		m_left * m_size * m_aspectRatio,
		m_right * m_size * m_aspectRatio,
		m_bottom * m_size,
		m_top * m_size,
		m_nearClip, m_farClip);

	RecalculateView();
}


void Camera2D::SetOrthographicUnits(float left, float right, float bottom, float top) {

	m_left = left;
	m_right = right;
	m_bottom = bottom;
	m_top = top;
	RecalculateProjection();
}
void Camera2D::RecalculateView() {
	m_viewMatrix = glm::lookAt(m_transform.GetPosition(),
		m_transform.GetPosition() - m_transform.GetForwardVector(),
		m_transform.GetUpVector());
}
void Camera2D::RecalculateProjection() {
	m_projectionMatrix = glm::ortho(
		m_left * m_size * m_aspectRatio,
		m_right * m_size * m_aspectRatio,
		m_bottom * m_size,
		m_top * m_size,
		m_nearClip, m_farClip);
}

const glm::mat4& Camera2D::GetViewMatrix() const {
	return m_viewMatrix;
}

glm::mat4& Camera2D::GetViewMatrix() {
	return m_viewMatrix;
}

const glm::mat4& Camera2D::GetProjectionMatrix() const {
	return m_projectionMatrix;
}

glm::mat4& Camera2D::GetProjectionMatrix() {
	return m_projectionMatrix;
}

void Camera2D::SetClipInterval(float near, float far) {
	m_nearClip = near;
	m_farClip = far;
}

void Camera2D::SetRotation(const glm::vec3& rot) {
	m_transform.SetRotation(rot);
	RecalculateView();
}

void Camera2D::AddRotation(const glm::vec3& deltaRot) {
	m_transform.AddRotation(deltaRot);
	RecalculateView();
}

void Camera2D::SetPosition(const glm::vec3& pos) {
	m_transform.SetPosition(pos);
	RecalculateView();
}

void Camera2D::AddPosition(const glm::vec3& deltaPos) {
	m_transform.AddPosition(deltaPos);
	RecalculateView();
}

void Camera2D::SetSize(float size) {
	m_size = size;
	RecalculateProjection();
}

void Camera2D::AddSize(float deltaSize) {
	m_size += deltaSize;
	RecalculateProjection();
}