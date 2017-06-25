#include "colors/rgb.h" 

#include <iomanip>
#include <sstream>

namespace colors
{

static RgbHex ToInt(const decltype(Rgb::r) value)
{
    return static_cast<RgbHex>(value);
}

static void FormatTwoCharHex(const decltype(Rgb::r) value, std::stringstream& outStream)
{
    const auto filler = '0';
    const auto width = 2;
    outStream << std::hex 
              << std::setfill(filler) 
              << std::setw(width)
              << ToInt(value);
}

auto Rgb::operator == (const Rgb& rhs) const -> bool
{
    return (this->r == rhs.r) && (this->g == rhs.g) && (this->b == rhs.b);
}

auto Rgb::operator != (const Rgb& rhs) const -> bool
{
    return (*this == rhs) == false;
}

auto operator <<(std::ostream& os, const Rgb& rgb) -> std::ostream&
{
    os << "{" << ToInt(rgb.r) << "," << ToInt(rgb.g) << "," << ToInt(rgb.b) << "}";
    return os;
}

auto operator "" _Rgb(const unsigned long long int hexValue) -> Rgb
{
   auto rgbHex = static_cast<RgbHex>(hexValue);
   return MakeRgb(rgbHex);
}

auto MakeHexString(const Rgb& rgb) -> std::string
{
    std::stringstream stream;
    FormatTwoCharHex(rgb.r, stream);
    FormatTwoCharHex(rgb.g, stream);
    FormatTwoCharHex(rgb.b, stream);
    return std::string(stream.str());
}


auto MakeHex(const Rgb& rgb) -> RgbHex
{
    const auto r{rgb.r << 16};
    const auto g{rgb.g << 8};
    return r + g + rgb.b;
}

auto MakeRgb(const RgbHex rgbHex) -> Rgb
{
    //assert(hexHex <= 0xFFFFFF);
    const auto r{static_cast<decltype(Rgb::r)>((rgbHex & 0xFF0000) >> 16)};
    const auto g{static_cast<decltype(Rgb::g)>((rgbHex & 0x00FF00) >> 8)};
    const auto b{static_cast<decltype(Rgb::b)>(rgbHex & 0x0000FF)};
    return Rgb{r, g, b};
}

} // namespace colors
