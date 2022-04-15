#pragma once
class menu {
private:

public:
	menu() {
		// Constructor
	};
	~menu() {
		//	Destructor
	};
	void ShowMenu();
	int SelectOption();
	void ProcessOption(int option);
};

