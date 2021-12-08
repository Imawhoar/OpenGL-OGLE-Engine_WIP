#pragma once

#include <vector>

#include "Camera2D.h"
#include "Actors/ActorObject.h"

namespace OGLE
{
	class Renderer {

	private:
		Camera2D* m_activeCamera = nullptr;
		std::vector<ActorObject*> m_actorList{};
	public:
		Renderer() {
			m_activeCamera = nullptr;
			m_actorList = {};
		}
		explicit Renderer(Camera2D* camera) {
			m_activeCamera = camera;
			m_actorList = {};
		}


	public:
		void SetActiveCamera(Camera2D* camera) {
			m_activeCamera = camera;
		}

		void RemoveRenderTarget(ActorObject* actor) {
			m_actorList.erase(std::remove(m_actorList.begin(), m_actorList.end(), actor), m_actorList.end());
		}
		void AddRenderTarget(ActorObject* actor) {
			m_actorList.push_back(actor);

		}


		void InputSetupActor(Input::InputManager* manager)
		{
			for (auto& actor : m_actorList)
			{
				actor->InputSetupActor(manager);
			}
		}
		void BeginActors()
		{
			for (auto& actor : m_actorList)
			{
				actor->BeginActor();
			}
		}
		
		void TickActors(float deltaTime)
		{
			for (auto& actor: m_actorList)
			{
				actor->TickActor(deltaTime);
			}
		}
		void Render() {

			const auto viewMat = m_activeCamera->GetViewMatrix();
			const auto projMat = m_activeCamera->GetProjectionMatrix();

			for (auto* target : m_actorList)
			{
				target->m_sprite->GetShader()->Bind();
				target->m_sprite->Bind();

				
				Matrix4 modelMatrix;

				auto translation = Matrix::Translate(Matrix4(1), target->GetTransform().GetPosition());
				auto rotation = target->GetTransform().GetQuaternion().ToMat4();
				auto scale = Matrix::Scale(Matrix4(1), target->GetTransform().GetScale());

				modelMatrix = translation * rotation * scale;
				
				target->m_sprite->GetShader()->SetMat4("modelMatrix", modelMatrix);
				target->m_sprite->GetShader()->SetMat4("viewMatrix", viewMat);
				target->m_sprite->GetShader()->SetMat4("projectionMatrix", projMat);

				target->m_sprite->Draw();
			}

		}
	};
}
