#pragma once

#include <cstdint>
#include <string>

namespace colors
{
    struct Rgb
    {
        const std::uint8_t r{0};
        const std::uint8_t g{0};
        const std::uint8_t b{0};
    };

    auto MakeHex(const Rgb& rgb) -> std::string;
}
