#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	vector <string> a;
	string word = "";
	set <string> word_s;
	set <string> word_f;

	while (word != "end") {
		cin >> word;
		a.push_back(word);
		if (word_s.count(word) == 0) {
			word_s.insert(word);

		}
		else {
			word_f.insert(word);

		}

	}

	for (string n : word_f) {
		cout << n << " ";
	}


	return 0;

}
