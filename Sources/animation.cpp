#include <Windows.h>
#include <iostream>
#include "../Sources/Headers/animation.h"

/*	Định nghĩa các hàm class 'animation' (Define 'animation' class functions)	*/
void animation::DotAnimation(int milliseconds) {
	for (int i = 0; i < 3; i++) {
		Sleep(milliseconds);
		std::cout << ".";
	}
}