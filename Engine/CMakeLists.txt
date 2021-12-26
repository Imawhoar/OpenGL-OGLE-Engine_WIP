project(engine)

add_library(engine
        Src/Core/Application.cpp
        Src/Core/Rect.cpp
        Src/Core/Texture.cpp
        Src/Core/Time.cpp
        Src/Core/Transform.cpp
        Src/Core/Transform.h
        Src/Core/Camera/Camera.cpp
        Src/Core/Camera/EditorCamera.cpp
        Src/Core/Camera/OrthographicCamera.cpp
        Src/Core/Input/InputAction.cpp
        Src/Core/Input/InputManager.cpp
        Src/Core/Renderer/Renderer.cpp
        Src/Tools/Template/TPureSingleton.h
        Src/Tools/Template/TRegistry.h
        Src/Tools/Template/TDelegate.h
        Src/Tools/FileHandler.h
        Src/Resources/Image.cpp
        Src/Resources/Shader.cpp
        Src/Utils/Color.cpp
        Src/Utils/Utils.h
        Src/World/DefaultWorldManager.cpp
        Src/World/World.cpp
        Src/World/WorldState.cpp
        Src/World/Actors/ActorBase.cpp
        Src/World/Scene/Scene.cpp
        Src/oglepch.h
        )
target_precompile_headers(engine PRIVATE Src/oglepch.h)
target_include_directories(engine
        PUBLIC
            Src
            ../ThirdParty/Glad/include
            ../ThirdParty/GLFW/include
            ../ThirdParty/entt/include
            ../ThirdParty/glm/include
            ../ThirdParty/spdlog/include
            ../ThirdParty/stb_image
        )

target_link_libraries(engine
        PUBLIC glfw
        PUBLIC glad
        )
