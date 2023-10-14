#include <iostream>
using namespace std;

int main() {
	int num, max_h = 2, cur_h = 1;
	cin >> num;
	bool floor = true;
	int i = 1;

	while (i <= num) {
		for (int j = 0; j < cur_h; j++) {
			if (i > num) {			
				break;
		
			}	
			cout << i++ << " ";
		}
		cout << endl;
		if (floor == true) {
			cur_h++;

		}else {
			cur_h--;		
		
		}

		if (cur_h == max_h || cur_h == 1) {
			floor = !floor;

		}

		if (cur_h == 1) {
			max_h++;
		
		}
	}

	return 0;

}
