#include <iostream>
#include <ios>
#include <string>

#include "colors/rgb.h"

int main()
{
    using namespace colors;

    // List of RGB values and their hex code counterparts.
    std::pair<Rgb, Rgb> colorPairs[] = {
        std::make_pair(0xffffff_Rgb, Rgb{255, 255, 255}),
        std::make_pair(0x000000_Rgb, Rgb{0, 0, 0}),
        std::make_pair(0x00ff00_Rgb, Rgb{0, 255, 0}),
        std::make_pair(0x7be720_Rgb, Rgb{123, 231,32}),
    };

    for (const auto& colorPair : colorPairs)
    {
        const auto& literal = colorPair.first;
        const auto& color = colorPair.second;

        // Test to see if the MakeHex function gave us the correct value.
        if (literal != color)
        {
            std::cout << "Expecting '" << color << "', got '" << literal << "'" << std::endl;
            return 1;
        }
    }

	return 0;
}
