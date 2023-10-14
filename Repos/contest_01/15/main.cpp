#include <iostream> 
#include <string>
using namespace std;

int main() {
	string s, result = "";
	cin >> s;

	int n = 0, nf = 1;

	while (n < s.length()) {
		result += s[n];
		while (s[n] == s[nf]){
			nf += 1;
		}
		if (nf - n > 1) {
			result += to_string(nf - n);
				
		}
		n = nf;
		nf++;
	}
	cout << result;
	
	return 0;
}
