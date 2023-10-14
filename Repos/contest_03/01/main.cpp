#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int>arr1;
	int n1, n2;
	
    cin >> n1;
	for (int i = 0; i < n1; i++) {
		int temp;
		cin >> temp;
		arr1.push_back(temp);	
	}
	
	cin >> n2;
	for (int i = 0; i < n2; i++) {
		int temp;
		cin >> temp;
		arr1.push_back(temp);
	}

	sort(begin(arr1), end(arr1));

	for (auto i : arr1) {
		cout << i << " ";
	}

}
