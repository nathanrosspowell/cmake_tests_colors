#include <iostream>
#include <ios>
#include <string>

#include "colors/black.h"
#include "colors/white.h"
#include "colors/ginger.h"
#include "colors/rgb.h"

int main()
{
    using namespace colors;

    // List of RGB values and their hex code counterparts.
    std::pair<const char* const, Rgb> colorPairs[] = {
        std::make_pair("ffffff", Rgb{255, 255, 255}),
        std::make_pair("000000", Rgb{0, 0, 0}),
        std::make_pair("00ff00", Rgb{0, 255, 0}),
        std::make_pair("7be720", Rgb{123, 231,32}),
    };

    for (const auto& colorPair : colorPairs)
    {
        const auto& target = colorPair.first;
        const auto& color = colorPair.second;
        const auto hex = MakeHex(color);

        // Test to see if the MakeHex function gave us the correct value.
        if (hex != target)
        {
            std::cout << "Expecting '" << target << "', got '" << hex << "'" << std::endl;
            return 1;
        }
    }

	return 0;
}
