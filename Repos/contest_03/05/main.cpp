#include <iostream>
#include <map>

using namespace std;

int main() {
	int n, max_count = 0;	
	string temp;
	cin >> n;
	map<string, unsigned> words;
	
	for (int i = 0; i < n; i++) {
		cin >> temp;
		words[temp] += 1;
	}
	
	for (const auto& element : words) {
		if (element.second > max_count) {
			max_count = element.second;
		}
	}

	for (const auto& element : words) {
		if (element.second == max_count) {
			cout << element.first << " ";
		}
	}


}
