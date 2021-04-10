#pragma once
#include "Transform.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/glm.hpp"

namespace OGLE
{
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
		Camera2D(float left, float right, float bottom, float top, float near, float far) {

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
		Camera2D(float near, float far) {

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
		Camera2D() {

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

		const glm::mat4& GetProjectionMatrix() const;
	};
}