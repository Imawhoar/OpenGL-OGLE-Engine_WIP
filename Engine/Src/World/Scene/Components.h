#pragma once
#include <utility>
#include "Core/Rect.h"
#include "Core/Transform.h"
#include "Core/Camera/OrthographicCamera.h"

//Instead of copy pasting code we just have this macro do it for use
#define DEFAULT_CONST_MOVE_ASSIGNABLE(name, type, var) \
name() = default;\
name(const name&) = default;\
name(type value) : var(std::move(value)) {}\
name(type && value) : var(std::move(value)) {}\
virtual ~name() = default;

namespace OGLE
{
	struct TagComponent
	{
		std::string tag;
		DEFAULT_CONST_MOVE_ASSIGNABLE(TagComponent, std::string, tag);
	};

	struct TransformComponent
	{
		Transform m_transform;
		DEFAULT_CONST_MOVE_ASSIGNABLE(TransformComponent, Transform, m_transform);
		TransformComponent(const Vector3& translation) { m_transform.SetPosition(translation); }
	};

	struct RectComponent
	{
		Rect rect;
		bool shouldRender = true;
		DEFAULT_CONST_MOVE_ASSIGNABLE(RectComponent, Rect, rect);
	};
	struct CameraComponent
	{
		//TODO: This should probably be both perspective and orthographic
		OrthographicCamera camera;
		DEFAULT_CONST_MOVE_ASSIGNABLE(CameraComponent, OrthographicCamera, camera);
	};

}
