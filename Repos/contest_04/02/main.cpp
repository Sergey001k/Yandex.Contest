#include <iostream>
#include <fstream>
#include "json.hpp"
#include <string>

//using namespace std;
using json = nlohmann::json;


int main() {
	int UserID;
	int count = 0;

	std::cin >> UserID;

	std::fstream file("data.json");
	json data = json::parse(file);

	for (auto project : data) {
		for (auto task : project["tasks"]) {

			int taskUserID = task["user_id"];
			bool taskCompl = task["completed"];

			if (taskUserID == UserID && taskCompl) {
				count++;
			}
		}
	}

	std::cout << count << "\n";
	return 0;
}