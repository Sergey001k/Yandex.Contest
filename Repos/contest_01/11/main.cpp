#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	
	if (abs(a - b) < abs(a - c)) {
		cout << "B" << " " << abs(a - b);
	}
    
	else {
		cout << "C" << " " << abs(a - c);
	}

	return 0;
}
