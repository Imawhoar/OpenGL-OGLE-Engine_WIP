#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/glm.hpp"

#include <string>
#include <memory>
#include <cstdint>

template<typename T>
using RefPtr = std::shared_ptr<T>;
template<typename T>
using URefPtr = std::unique_ptr<T>;


typedef uint8_t  uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef int8_t    int8;
typedef int16_t   int16;
typedef int32_t   int32;
typedef int64_t   int64;
