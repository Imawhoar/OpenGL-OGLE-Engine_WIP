#pragma once
#include <vector>

namespace OGLE
{
	class Scene;
	class Renderer final
	{
	private:
		Scene* m_scene;
	public:
		Renderer() = default;

	public:
		void Render() const;
	};
}
