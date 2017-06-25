#pragma once

#include <cstdint>
#include <string>

namespace colors
{

struct Rgb
{
    const std::uint8_t r{0}, g{0}, b{0};

    auto operator == (const Rgb& rhs) const -> bool;
    auto operator != (const Rgb& rhs) const -> bool;
};

using RgbHex = std::uint32_t;

auto operator <<(std::ostream& os, const Rgb& rgb) -> std::ostream&;

auto operator "" _Rgb(const unsigned long long inthexValue) -> Rgb;

auto MakeHexString(const Rgb& rgb) -> std::string;

auto MakeHex(const Rgb& rgb) -> RgbHex;

auto MakeRgb(const RgbHex rgbHex) -> Rgb;

} // namespace colors
