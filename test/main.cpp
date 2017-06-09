#include <iostream>
#include <ios>

#include "colors/black.h"
#include "colors/white.h"
#include "colors/ginger.h"

int main()
{
	Black b;
	White w;
	Ginger g;

	std::cout << b.ToString() <<  "==" << std::hex << b.ToRGB() << std::endl;
	std::cout << w.ToString() <<  "==" << std::hex << w.ToRGB() << std::endl;
	std::cout << g.ToString() <<  "==" << std::hex << g.ToRGB() << std::endl;

	return 0;
}
