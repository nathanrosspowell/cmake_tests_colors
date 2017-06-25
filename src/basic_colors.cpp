#include "colors/basic_colors.h"

namespace colors
{

auto BasicColors() -> std::unordered_map<std::string, Rgb>
{
    return {
        {"white", 0xFFFFFF_Rgb},
        {"black", 0x000000_Rgb},
        {"red", 0xFF0000_Rgb},
        {"green", 0x00FF00_Rgb},
        {"blue", 0x0000FF_Rgb},
    };
}

} // namespace colors
