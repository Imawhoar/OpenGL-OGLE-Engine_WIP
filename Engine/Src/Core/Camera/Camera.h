#pragma once
#include "OEPCH.h"
#include "Utils/Matrix.h"


namespace OGLE
{
	struct OrthographicSettings
	{
		float left{}, right{};
		float bottom{}, top{};

		OrthographicSettings(float left, float right, float bottom, float top, float size)
			: left(left),
			right(right),
			bottom(bottom),
			top(top),
			size(size)
		{
		}

		float size{};
		OrthographicSettings() : left(1), right(1), bottom(1), top(1), size(5) {}
	};
	struct PerspectiveSettings
	{
		float fieldOfView;

		PerspectiveSettings(float fieldOfView, float width, float height)
			: fieldOfView(fieldOfView),
			width(width),
			height(height) {
		}

		float width, height;
		PerspectiveSettings() : fieldOfView(70.0f), width(1920), height(1080) {}
	};
	enum class CameraType
	{
		PERSPECTIVE,
		ORTHOGRAPHIC
	};
	class Camera {

	protected:
		Matrix4 m_projectionMatrix{};
		float m_nearClip = 0.001f, m_farClip = 1000.0f;

	public:
		Camera() = default;

		const auto& GetProjectionMatrix() const;
	};

};

