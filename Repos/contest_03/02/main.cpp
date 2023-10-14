#include <iostream>
#include <stack>

using namespace std;

bool balance() {
	char c;
	stack<char> stk;
	while ((c = cin.get()) != '!') {
		if (c == '(') {
			stk.push(')');
		}

		if (c == '[') {
			stk.push(']');
		}

		if (c == '{') {
			stk.push('}');
		}

		if (c == ')' || c == '}' || c == ']') {
			if (stk.empty()) return false;
			if (stk.top() != c) return false;
			else stk.pop();
		}
	}
	if (!stk.empty()) return false;
	
	return true;


}

int main() {
	cout << (balance() ? "YES" : "NO");
}


