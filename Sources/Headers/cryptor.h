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
	void Encrypt(std::string filename, int pin);
	void Decrypt(std::string filename, int pin);
};

