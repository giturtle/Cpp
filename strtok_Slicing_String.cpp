

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	std::string str("Please split this sentence into tokens");

	char * cstr = new char[str.length() + 1];
	std::strcpy(cstr, str.c_str());

	char * p = std::strtok(cstr, " ");
	while (p != 0){
		std::cout << p << '\n';
		p = std::strtok(NULL, " ");
	}

	delete[] cstr;
	system("pause");
	return 0;
}
