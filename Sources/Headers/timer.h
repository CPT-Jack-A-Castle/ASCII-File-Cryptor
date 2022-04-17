#pragma once
class timer {
private:

public:
	DWORD start;
	DWORD end;
	double calc;
	timer() {
		//	Constructor
	}
	~timer() {
		//	Destructor
	}
	void Start();
	void End();
	void Calc();
};

