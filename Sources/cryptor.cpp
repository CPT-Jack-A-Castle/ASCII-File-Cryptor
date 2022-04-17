#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include "../Sources/Headers/cryptor.h"
#include "../Sources/Headers/animation.h"

/*	Tạo object từ classes (Create object from classes)	*/
animation AnimationCryptorObj;

/*	Định nghĩa các hàm class 'cryptor' (Define 'cryptor' class functions)	*/
void cryptor::Encrypt(std::string filename, int pin) {
	DWORD dw1;
	DWORD dw2;
	double dw3;
	char i;
	dw1 = GetTickCount64();
	std::string OriginalFileName = filename;
	std::string TempData;
	std::ifstream InputFile(filename, std::ios::binary);
	std::ofstream CryptFile("crypting", std::ios::binary);
	if (!InputFile) {
		InputFile.close();
		CryptFile.close();
		system("del /f crypting");
		std::cout << "Không tìm thấy hoặc không thể truy cập file ";
		AnimationCryptorObj.DotAnimation(500);
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		goto escape;
	}
	if (!CryptFile) {
		std::cout << "Không thể tạo file tạm thời (Thiếu quyền?) ";
		AnimationCryptorObj.DotAnimation(500);
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		goto escape;
	}
	while (InputFile >> std::noskipws >> i) {
		i = i + pin;
		TempData += i;
	}
	CryptFile << TempData;
	std::cout << "Tệp đã được mã hoá với mã PIN: " << pin << std::endl;
	Sleep(1000);
	InputFile.close();
	CryptFile.close();
	system(("del /f " + OriginalFileName).c_str());
	system(("ren crypting " + OriginalFileName).c_str());
	dw2 = GetTickCount64();
	dw3 = dw2 - dw1;
	dw3 = dw3 / 1000;
	std::cout << "Quá trình mã hoá tốn " << dw3 << " giây." << std::endl;
	system("pause");
escape:
	std::cout << "";
}

void cryptor::Decrypt(std::string filename, int pin) {
	DWORD dw1;
	DWORD dw2;
	double dw3;
	char i;
	dw1 = GetTickCount64();
	std::string OriginalFileName = filename;
	std::string TempData;
	std::ifstream InputFile(filename, std::ios::binary);
	std::ofstream DecryptFile("decrypting", std::ios::binary);
	if (!InputFile) {
		InputFile.close();
		DecryptFile.close();
		system("del /f decrypting");
		std::cout << "Không tìm thấy hoặc không thể truy cập file ";
		AnimationCryptorObj.DotAnimation(500);
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		goto escape;
	}
	if (!DecryptFile) {
		std::cout << "Không thể tạo file tạm thời (Thiếu quyền?) ";
		AnimationCryptorObj.DotAnimation(500);
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		goto escape;
	}
	while (InputFile >> std::noskipws >> i) {
		i = i - pin;
		TempData += i;
	}
	DecryptFile << TempData;
	std::cout << "Tệp đã được giải mã với mã PIN: " << pin << std::endl;
	Sleep(1000);
	InputFile.close();
	DecryptFile.close();
	system(("del /f " + OriginalFileName).c_str());
	system(("ren decrypting " + OriginalFileName).c_str());
	dw2 = GetTickCount64();
	dw3 = dw2 - dw1;
	dw3 = dw3 / 1000;
	std::cout << "Quá trình giải mã tốn " << dw3 << " giây." << std::endl;
	system("pause");
escape:
	std::cout << "";
}