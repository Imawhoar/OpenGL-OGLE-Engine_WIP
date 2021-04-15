#pragma once
#include "Transform.h"
#include "Utils/Matrix.h"
#include "Utils/Vector.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/glm.hpp"

namespace OGLE
{
	class Camera2D {

	private:

		Transform m_transform{};
		Matrix4 m_viewMatrix{};
		Matrix4 m_projectionMatrix{};

		float m_left{}, m_right{};
		float m_bottom{}, m_top{};

		float m_size{};
		float m_aspectRatio{};

		float m_nearClip = 0.001f, m_farClip = 1000.0f;


	private:
		void RecalculateView() {
			m_viewMatrix = glm::lookAt(m_transform.GetPosition(),
				m_transform.GetPosition() - m_transform.GetFront(),
				m_transform.GetUp());
		}
		void RecalculateProjection() {
			m_projectionMatrix = glm::ortho(
				m_left * m_size * m_aspectRatio,
				m_right * m_size * m_aspectRatio,
				m_bottom * m_size,
				m_top * m_size,
				m_nearClip, m_farClip);
		}

	public:
		Camera2D(float left, float right, float bottom, float top, float nearClip, float farClip) {

			m_transform.SetPosition(Vector3(0, 0, 10));
			m_transform.SetRotation(Vector3(0, 0, 0));

			m_size = 5;

			m_aspectRatio = 16.0f / 9.0f;
			SetClipInterval(nearClip, farClip);

			m_left = left;
			m_right = right;
			m_bottom = bottom;
			m_top = top;

			RecalculateProjection();
			RecalculateView();
		}
		Camera2D(float nearClip, float farClip) {

			m_transform.SetPosition(Vector3(0, 0, 10));
			m_transform.SetRotation(Vector3(0, 0, 0));

			m_size = 5;

			m_aspectRatio = 16.0f / 9.0f;

			m_left = -1;
			m_right = 1;
			m_bottom = -1;
			m_top = 1;

			SetClipInterval(nearClip, farClip);
			m_projectionMatrix = glm::ortho(
				m_left * m_size * m_aspectRatio,
				m_right * m_size * m_aspectRatio,
				m_bottom * m_size,
				m_top * m_size,
				nearClip, farClip);

			RecalculateView();
		}
		Camera2D() {

			m_transform.SetPosition(Vector3(0, 0, 10));
			m_transform.SetRotation(Vector3(0, 0, 0));

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
		void SetRotation(const Vector3& rot) {
			m_transform.SetRotation(rot);
			RecalculateView();
		}
		void AddRotation(const Vector3& deltaRot) {
			m_transform.AddRotation(deltaRot);
			RecalculateView();
		}
		
		void SetPosition(const Vector3& pos) {
			m_transform.SetPosition(pos);
			RecalculateView();
		}
		void AddPosition(const Vector3& deltaPos) {
			m_transform.AddPosition(deltaPos);
			RecalculateView();
		}

		void SetOrthographicUnits(float left, float right, float bottom, float top) {

			m_left = left;
			m_right = right;
			m_bottom = bottom;
			m_top = top;
			RecalculateProjection();
		}
		void SetClipInterval(float nearClip, float farClip) {
			m_nearClip = nearClip;
			m_farClip = farClip;
		}

		void SetSize(float size) {
			m_size = size;
			RecalculateProjection();
		}
		void AddSize(float deltaSize) {
			m_size += deltaSize;
			RecalculateProjection();
		}

		[[nodiscard]] const auto& GetViewMatrix() const {
			return m_viewMatrix;
		}

		[[nodiscard]] const auto& GetProjectionMatrix() const {
			return m_projectionMatrix;
		}
	};
}