#include <iostream>
#include <string>

using namespace std;

int main() {
	string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string result = "";
	
	int num;
	cin >> num;

		
	while (num > 0) {
		num--;
		result = s[num % 26] + result;
		num /= 26;
	}
	cout << result;

	return 0;
}
