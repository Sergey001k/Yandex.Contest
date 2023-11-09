#include <iostream>
#include <stdlib.h>

using namespace std;

class Cat
{
	bool alive;

public:
	Cat() {
		alive = true;
	}

	bool is_alive() {
		return alive;
	}

	void set_alive(bool val) {
		alive = val;
	}


};

class Box
{
public:
	Cat open() {
		Cat cat;

		if (rand() % 2 == 0) {
			cat.set_alive(false);
		}
		return cat;

	}

};

