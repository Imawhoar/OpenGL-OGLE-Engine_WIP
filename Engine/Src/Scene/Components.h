#pragma once
#include <string>
#include <utility>
#include "OGLE.h"

namespace OGLE
{

	struct TagComponent
	{
		std::string Tag;

		TagComponent() = default;
		TagComponent(const TagComponent&) = default;
		TagComponent(std::string tag) : Tag(std::move(tag)) {}
		TagComponent(std::string&& tag) : Tag(std::move(tag)) {}
		virtual ~TagComponent() = default;

	};

	struct TransformComponent
	{
		Transform transform;
		TransformComponent() = default;
		TransformComponent(const TransformComponent&) = default;
		TransformComponent(const glm::vec3& translation) { transform.SetPosition(translation); }
		virtual ~TransformComponent() = default;
		
		[[nodiscard]] Matrix4 GetTransform() const
		{
			return glm::translate(glm::mat4(1.0f), transform.GetPosition())
				* Quaternion(transform.GetRotation()).ToMat4()
				* glm::scale(glm::mat4(1.0f), transform.GetScale());
		}
	};

}
