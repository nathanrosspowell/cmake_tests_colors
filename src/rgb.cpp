#include "colors/rgb.h" 

#include <iomanip>

namespace colors
{
    auto MakeHex(const Rgb& rgb) -> std::string
    {
        const auto filler = '0';
        const auto width = 2;
        std::stringstream stream;
        stream << std::hex << std::setfill(filler) << std::setw(width)
               << static_cast<std::uint32_t>(rgb.r);
        stream << std::hex << std::setfill(filler) << std::setw(width)
               << static_cast<std::uint32_t>(rgb.g);
        stream << std::hex << std::setfill(filler) << std::setw(width)
               << static_cast<std::uint32_t>(rgb.b);
        return std::string(stream.str());
    }
}
