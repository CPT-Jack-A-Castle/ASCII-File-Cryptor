#include <Windows.h>
#include <iostream>
#include "../Sources/Headers/animation.h"

void animation::DotAnimation(int milliseconds) {
	for (int i = 0; i < 3; i++) {
		Sleep(milliseconds);
		std::cout << ".";
	}
}