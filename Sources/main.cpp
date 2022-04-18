#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "../Sources/Headers/menu.h"
#include "../Sources/Headers/cryptor.h"
#include "../Sources/Headers/animation.h"

/*	Tạo object từ classes (Create object from classes)	*/
menu MenuMainObj;

using namespace std;

int main() {
	SetConsoleOutputCP(65001);	//	Hỗ trợ văn bản utf-8 (Support utf-8)
	while (true) {
		SetConsoleTitle(L"ASCII File Cryptor");
		MenuMainObj.ProcessOption(MenuMainObj.SelectOption());
	}
	return 0;
}