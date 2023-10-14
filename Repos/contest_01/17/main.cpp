#include <iostream>
#include <vector>

using namespace std;

int main() {
	long l_max = 0, r_max = 0, l_cur, r_cur, water = 0, n, elem;
	cin >> n;
	vector<long> island;
	l_cur = 0;
	r_cur = n - 1;

	for (int i = 0; i < n; i++) {
		cin >> elem;
		island.push_back(elem);
	}

	l_max = island[l_cur];
	r_max = island[r_cur];


	while (l_cur < r_cur){
		if (l_max >= r_max){
			water += r_max - island[r_cur];
			r_cur--;

			if (r_max < island[r_cur]) { 
				r_max = island[r_cur];
			}
		}
		else {
			water += l_max - island[l_cur];
			l_cur++;

			if (l_max < island[l_cur]) { 
				l_max = island[l_cur];
			}

		}
	
	}
	
	cout << water;

	return 0;

}
