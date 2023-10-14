#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
	map<string, int> users;
	vector<string> search;
	
  int n_users, n_search;
	stringstream ss;
	
  cin >> n_users;
	cin.ignore(1);
	string temp1, temp2;	

	for (int i = 0; i < n_users; i++) {
		getline(cin, temp1);
		ss << temp1;
		getline(ss, temp1, ';');
		getline(ss, temp2, ' ');
		
		users[temp1] = stoi(temp2);
		ss.clear();
	}
		
	cin >> n_search;
	for (int i = 0; i < n_search; i++) {
		string temp;
		cin >> temp;
		search.push_back(temp);

	}
	
	for (string i : search) {
		cout << users[i] << " ";

	}
	
	return 0;
}
