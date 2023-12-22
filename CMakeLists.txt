cmake_minimum_required(VERSION 3.26)
project(PixelPaddle)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)
set(SDL2_PATH ${CMAKE_SOURCE_DIR}/libs/SDL2)
set(SDL2_IMAGE_PATH ${CMAKE_SOURCE_DIR}/libs/SDL2_Image)
set(CMAKE_EXE_LINKER_FLAGS "-static")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})
add_executable(PixelPaddle main.cpp
        src/engine/GameRenderer.cpp
        include/engine/GameRenderer.h
        src/engine/GameObject.cpp
        include/engine/GameObject.h
        src/engine/Vector2.cpp
        include/engine/Vector2.h
        src/engine/Renderer.cpp
        include/engine/Renderer.h
        src/engine/Collider.cpp
        include/engine/Collider.h
        src/engine/Component.cpp
        include/engine/Component.h
        src/engine/GameManager.cpp
        include/engine/GameManager.h
        include/Constants.h
        src/engine/InputManager.cpp
        include/engine/InputManager.h
        src/engine/Transform.cpp
        include/engine/Transform.h
)
target_link_libraries(
        ${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/libs/SDL2/lib/libSDL2.dll.a ${CMAKE_SOURCE_DIR}/libs/SDL2/lib/libSDL2main.a
        ${CMAKE_SOURCE_DIR}/libs/SDL2_Image/lib/libSDL2_image.dll.a)