#pragma once
#include "glm/gtc/matrix_transform.hpp"
#include "Transform.h"

class Camera2D {

private:

	Transform m_transform{};
	glm::mat4 m_viewMatrix{};
	glm::mat4 m_projectionMatrix{};

	float m_left{}, m_right{};
	float m_bottom{}, m_top{};

	float m_size{};
	float m_aspectRatio{};

	float m_nearClip = 0.001f, m_farClip = 1000.0f;


private:
	void RecalculateView();
	void RecalculateProjection();

public:
	Camera2D(float left, float right, float bottom, float top, float near, float far);
	Camera2D(float near, float far);
	Camera2D();

public:
	void SetRotation(const glm::vec3& rot);
	void AddRotation(const glm::vec3& deltaRot);

	void SetPosition(const glm::vec3& pos);
	void AddPosition(const glm::vec3& deltaPos);

	void SetOrthographicUnits(float left, float right, float bottom, float top);
	void SetClipInterval(float near, float far);

	void SetSize(float size);
	void AddSize(float deltaSize);

	const glm::mat4& GetViewMatrix() const;
	glm::mat4& GetViewMatrix();

	const glm::mat4& GetProjectionMatrix() const;
	glm::mat4& GetProjectionMatrix();
};