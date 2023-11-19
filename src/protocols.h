#pragma once

#include <cstddef>

namespace PA3
{
constexpr auto linearInit = 2;
constexpr auto binaryExpInit = 2;
constexpr auto logLogInit = 4;

size_t linear(size_t windowSize);
size_t binaryExp(size_t windowSize);
size_t logLog(size_t windowSize);
}
