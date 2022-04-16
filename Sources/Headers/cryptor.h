#pragma once
class cryptor {
private:

public:
	cryptor() {
		//	Constructor
	}
	~cryptor() {
		//	Destructor
	}
	/*	Khai báo hàm mẫu (Declare function prototypes)	*/
	void Encrypt(std::string filename, int pin);
	void Decrypt(std::string filename, int pin);
};

