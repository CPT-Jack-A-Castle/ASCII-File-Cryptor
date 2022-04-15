#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "../Sources/Headers/menu.h"
#include "../Sources/Headers/cryptor.h"
#include "../Sources/Headers/animation.h"

menu MenuMainObj;

using namespace std;

int main() {
	SetConsoleOutputCP(65001);
	while (true) {
		MenuMainObj.ProcessOption(MenuMainObj.SelectOption());
	}
	return 0;
}