#include <iostream>;
#include <cmath>
using namespace std;

int main() {
	double b = -3, p = 1;
	double a = 3, result = 1;
	for (int i = 1; i <= 5; i++) {
		result += (1 / (a * (pow(b, p))));
		a += 2;
		p += 1;

	}
	result = sqrt(12) * (result);
	cout << result;
		
	return 0;

}
