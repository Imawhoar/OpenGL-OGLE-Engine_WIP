#include "Renderer.h"
#include <algorithm>
#include "glm/gtc/matrix_transform.hpp"

namespace OGLE
{
	Renderer::Renderer(Camera2D* camera) {
		m_activeCamera = camera;
		m_spriteList = {};
	}

	Renderer::Renderer() {
		m_activeCamera = nullptr;
		m_spriteList = {};
	}


	void Renderer::RemoveRenderTarget(Sprite* sprite) {
		m_spriteList.erase(std::remove(m_spriteList.begin(), m_spriteList.end(), sprite), m_spriteList.end());
	}

	void Renderer::AddRenderTarget(Sprite* sprite) {
		m_spriteList.push_back(sprite);

	}

	void Renderer::SetActiveCamera(Camera2D* camera) {
		m_activeCamera = camera;
	}


	float x = 0;
	void Renderer::Render() {
		
		const auto viewMat = m_activeCamera->GetViewMatrix();
		const auto projMat = m_activeCamera->GetProjectionMatrix();

		//auto projMat = glm::perspective(50.0f, 16.0f/9, 0.01f, 100.0f);

		for (auto target : m_spriteList)
		{
			target->GetShader()->use();
			target->bind();
			glm::mat4 modelMatrix(1);

			modelMatrix = glm::translate(modelMatrix, target->GetTransform().GetPosition());

			modelMatrix = glm::rotate(modelMatrix, target->GetTransform().GetRotation().x, glm::vec3(1, 0, 0));
			modelMatrix = glm::rotate(modelMatrix, target->GetTransform().GetRotation().y, glm::vec3(0, 1, 0));
			modelMatrix = glm::rotate(modelMatrix, target->GetTransform().GetRotation().y, glm::vec3(0, 0, 1));

			modelMatrix = glm::scale(modelMatrix, target->GetTransform().GetScale());

			target->GetShader()->setMat4("modelMatrix", modelMatrix);
			target->GetShader()->setMat4("viewMatrix", viewMat);
			target->GetShader()->setMat4("projectionMatrix", projMat);

			target->draw();
		}

	}
}