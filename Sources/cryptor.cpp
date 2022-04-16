#include <iostream>
#include <fstream>
#include "../Sources/Headers/cryptor.h"
#include "../Sources/Headers/animation.h"

animation AnimationCryptorObj;

void cryptor::Encrypt(std::string filename, int pin) {
	char i;
	std::fstream InputFile, TemporyFile;
	InputFile.open(filename, std::fstream::in);
	if (!InputFile) {
		std::cout << "Không tìm thấy hoặc không thể truy cập file ";
		AnimationCryptorObj.DotAnimation(500);
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		goto escape;
	}
	TemporyFile.open("process", std::fstream::out);
	if (!TemporyFile) {
		std::cout << "Không thể tạo file tạm thời ";
		AnimationCryptorObj.DotAnimation(500);
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		goto escape;
	}
	while (InputFile >> std::noskipws >> i) {
		i = i + pin;
		TemporyFile << i;
	}
	InputFile.close();
	TemporyFile.close();
	InputFile.open(filename, std::fstream::out);
	if (!InputFile) {
		std::cout << "Không tìm thấy hoặc không thể truy cập file ";
		AnimationCryptorObj.DotAnimation(500);
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		goto escape;
	}
	TemporyFile.open("process", std::fstream::in);
	if (!TemporyFile) {
		std::cout << "Không thể tạo file tạm thời ";
		AnimationCryptorObj.DotAnimation(500);
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		goto escape;
	}
	while (TemporyFile >> std::noskipws >> i) {
		InputFile << i;
	}
	InputFile.close();
	TemporyFile.close();
	std::cout << "Tệp đã được mã hoá với mã PIN: " << pin << std::endl;
	system("del /f process");
	system("pause");
escape:
	std::cout << "";
}

void cryptor::Decrypt(std::string filename, int pin) {
	char i;
	std::fstream InputFile, TemporyFile;
	InputFile.open(filename, std::fstream::in);
	if (!InputFile) {
		std::cout << "Không tìm thấy hoặc không thể truy cập file ";
		AnimationCryptorObj.DotAnimation(500);
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		goto escape;
	}
	TemporyFile.open("process.txt", std::fstream::out);
	if (!TemporyFile) {
		std::cout << "Không thể tạo file tạm thời ";
		AnimationCryptorObj.DotAnimation(500);
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		goto escape;
	}
	while (InputFile >> std::noskipws >> i) {
		i = i - pin;
		TemporyFile << i;
	}
	InputFile.close();
	TemporyFile.close();
	InputFile.open(filename, std::fstream::out);
	if (!InputFile) {
		std::cout << "Không tìm thấy hoặc không thể truy cập file ";
		AnimationCryptorObj.DotAnimation(500);
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		goto escape;
	}
	TemporyFile.open("process.txt", std::fstream::in);
	if (!TemporyFile) {
		std::cout << "Không thể tạo file tạm thời ";
		AnimationCryptorObj.DotAnimation(500);
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		goto escape;
	}
	while (TemporyFile >> std::noskipws >> i) {
		InputFile << i;
	}
	InputFile.close();
	TemporyFile.close();
	std::cout << "Tệp đã được giải mã với mã PIN: " << pin << std::endl;
	system("del /f process.txt");
	system("pause");
escape:
	std::cout << "";
}