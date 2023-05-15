#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPriority(char op) {
    int priority = 0;
    if (op == '+' || op == '-') {
        priority = 1;
    } else if (op == '*' || op == '/') {
        priority = 2;
    }
    return priority;
}

void generateThreeAddressCode(string expression) {
    stack<char> operators;
    stack<string> operands;
    int len = expression.length();
    for (int i = 0; i < len; i++) {
        if (isOperator(expression[i])) {
            while (!operators.empty() && getPriority(operators.top()) >= getPriority(expression[i])) {
                char op = operators.top();
                operators.pop();
                string op2 = operands.top();
                operands.pop();
                string op1 = operands.top();
                operands.pop();
                string temp = "t" + to_string(i);
                cout << temp << " = " << op1 << " " << op << " " << op2 << endl;
                operands.push(temp);
            }
            operators.push(expression[i]);
        } else {
            string operand;
            while (i < len && isalnum(expression[i])) {
                operand += expression[i];
                i++;
            }
            i--;
            operands.push(operand);
        }
    }
    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();
        string op2 = operands.top();
        operands.pop();
        string op1 = operands.top();
        operands.pop();
        string temp = "t" + to_string(len);
        cout << temp << " = " << op1 << " " << op << " " << op2 << endl;
        operands.push(temp);
    }
    cout << operands.top() << endl;
}

int main() {
    string expression;
    cout << "Enter an arithmetic expression: ";
    cin >> expression;
    generateThreeAddressCode(expression);
    return 0;
}
