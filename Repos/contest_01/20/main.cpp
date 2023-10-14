#include <iostream>
#include <set>
using namespace std;

int main() {
	long num1, num2;
	cin >> num1 >> num2;
	set<int> dig1;
	set<int> dig2;

	while (num1 != 0) {
		dig1.insert(num1%10);
		num1 /= 10;
	}

	while (num2 != 0) {
		dig2.insert(num2 % 10);
		num2 /= 10;
	}

	if (dig1 == dig2) {
		cout << "YES";

	}
	else {
		cout << "NO";
	}
	
	return 0;
}
