#include <iostream>
#include <set>
#include <string>

using namespace std;

set<string> sim_words(set<string> set1, set<string> set2) {
	set<string> result;
	if (set1.size() >= set2.size()) {
		for (auto i : set1) {
			if (set2.count(i) >= 1) {
				result.insert(i);
			}
		}
	}

	if (set1.size() < set2.size()) {
		for (auto i : set2) {
			if (set1.count(i) >= 1) {
				result.insert(i);
			}
		}
	}
	return result;

}

void contain(set<string> *con) {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		(*con).insert(temp);
	}

}


int main() {
	set<string> line1;
	set<string> line2;
	contain(&line1);
	contain(&line2);

	if (sim_words(line1, line2).size() == 0) {
		cout << -1;
	}
	for (auto i : sim_words(line1, line2)) {
		cout << i << " ";
	}

}

