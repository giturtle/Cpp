




//最难的问题

#include <iostream>
#include <string>
using namespace std;
int main() {
	string pass1;
	while (getline(cin, pass1)) {
		for (int i = 0; i < (int)pass1.size(); ++i) {
            if (isspace(pass1[i]))
				continue;
			if (pass1[i] - 5 < 'A') {
				pass1[i] += 21;
				continue;
			}
			pass1[i] -= 5;
		}
		cout << pass1.c_str() << endl;
	}
	return 0;
}
