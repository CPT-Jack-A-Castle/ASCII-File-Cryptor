#include <Windows.h>
#include <iostream>
#include "animation.h"

void animation::DotAnimation(int milliseconds) {
	for (int i = 0; i < 3; i++) {
		Sleep(milliseconds);
		std::cout << ".";
	}
}