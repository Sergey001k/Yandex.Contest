#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> split(string s, char delimiter) {
	vector<string> result;
	string temp = "";
	bool markOpen = false;

	for (int i = 0; i < s.size(); i++) {

		if (s[i] == '"') {
			markOpen = !markOpen;
		}

		if (s[i] != delimiter || markOpen) {
			if (s[i] == '"' && (i + 1 < s.size()) && s[i] == s[i + 1]) {
				temp += '"';
				i++;
			}
			else if (s[i] != '"') {
				temp += s[i];
			}
		}

		else {
			result.push_back(temp);
			temp = "";
		}
	}
	result.push_back(temp);
	
	return result;
}

vector<vector<string>> readCSV(string filename) {
	vector<vector<string>> result;
	ifstream file(filename);
	string line;

	while (not file.eof()) {
		getline(file, line, '\r');
		result.push_back(split(line, ','));
	}

	return result;
}

bool compare(pair<int, string> element1, pair<int, string> element2) {
	if (element1.first != element2.first) {
		return element1.first < element2.first;
	}
	else {
		return element1.second < element2.second;
	}
}

int main() {
	int pclass, age;
	vector<vector<string>> data;
	vector<pair<int, string>> people;

	cin >> pclass >> age;

	data = readCSV("train.csv");
	data.erase(data.begin());

	for (auto i : data) {
		if (i[5] == "") {
			i[5] = '0';
		}
		
		if (stoi(i[2]) == pclass && i[4] == "female" && stoi(i[5]) > age){
			pair<int, string> temp;
			temp.first = stoi(i[5]);
			temp.second = i[3];
			people.push_back(temp);

		}
	}

	sort(begin(people), end(people), compare);
	
	for (auto i : people) {
		cout << i.second << endl;
	}

	return 0;

}