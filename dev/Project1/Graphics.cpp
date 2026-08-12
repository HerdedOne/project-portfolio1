#include "Graphics.h"
#include <iostream>

void Graphics::clear() //clears the screen
{
	std::cout << "\033[H\033[2J" << std::flush;
}
