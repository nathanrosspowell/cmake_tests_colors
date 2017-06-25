#pragma once

#include <string>
#include <unordered_map>

#include "colors/rgb.h"

namespace colors
{

auto BasicColors() -> std::unordered_map<std::string, Rgb>;

} // namespace colors
