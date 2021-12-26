#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <string>
#include <memory>
#include <cstdint>
#include <vector>

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX // See github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-min-the-max-and-the-macro
#endif
#endif

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
