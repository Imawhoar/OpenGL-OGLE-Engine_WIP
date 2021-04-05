#pragma once

#include <vector>
#include "glm/mat4x4.hpp"

class Camera2D;
class Sprite;

class Renderer {

private:
	Camera2D* m_activeCamera = nullptr;
	std::vector<Sprite*> m_spriteList{};
public:
	Renderer();
	explicit Renderer(Camera2D* camera);

public:
	void SetActiveCamera(Camera2D* camera);

	void RemoveRenderTarget(Sprite* sprite);
	void AddRenderTarget(Sprite* sprite);

	void Render();
};
