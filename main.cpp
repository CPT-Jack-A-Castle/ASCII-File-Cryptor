#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "menu.h"
#include "cryptor.h"
#include "animation.h"

menu MenuMainObj;

using namespace std;

int main() {
	SetConsoleOutputCP(65001);
	while (true) {
		MenuMainObj.ProcessOption(MenuMainObj.SelectOption());
	}
	return 0;
}