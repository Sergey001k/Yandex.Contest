#include <iostream>
#include <stack>
#include <string>

using namespace std;

int getOperatorPriority(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    
    return 0;
}

string infixToRPN(string expression) {
    string result;
    stack<char> operators;

    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            result += expression[i];

            while (i + 1 < expression.length() && expression[i + 1] >= '0' && expression[i + 1] <= '9') {
                result += expression[i + 1];
                i++;
            }
            result += ' ';
        }
        else if (expression[i] == '(') {
            operators.push(expression[i]);
        }
        else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                result += operators.top();
                operators.pop();
                result += ' ';
            }
            operators.pop(); 
        }
        else {
            while (!operators.empty() && getOperatorPriority(operators.top()) >= getOperatorPriority(expression[i])) {
                if (getOperatorPriority(operators.top()) == getOperatorPriority(expression[i]) && operators.top() == '^') {
                    break;
                }
                result += operators.top();
                operators.pop();
                result += ' ';
                
            }
            operators.push(expression[i]);
        }
    }

    while (!operators.empty()) {
        result += operators.top();
        operators.pop();
        result += ' ';
    }

    return result;
}

int main() {
    string expression;
    getline(cin, expression);

    cout << infixToRPN(expression) << endl;

    return 0;
}

