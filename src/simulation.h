#pragma once

#include <cstddef>
#include <string>
#include <functional>

namespace PA3
{
size_t simlulate(std::function<size_t(size_t)> protocol, size_t protocolInit, size_t devices);
}
