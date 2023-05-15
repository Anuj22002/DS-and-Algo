#include <iostream>
#include <string>
#include <stdexcept>

class RecursiveDescentParser {
public:
    RecursiveDescentParser(const std::string& input)
        : input(input), position(0) {}

    int parse() {
        return parseExpression();
    }

private:
    int parseExpression() {
        int result = parseTerm();
        while (position < input.length() && (input[position] == '+' || input[position] == '-')) {
            char op = input[position++];
            int rhs = parseTerm();
            if (op == '+') {
                result += rhs;
            } else {
                result -= rhs;
            }
        }
        return result;
    }

    int parseTerm() {
        int result = parseFactor();
        while (position < input.length() && (input[position] == '*' || input[position] == '/')) {
            char op = input[position++];
            int rhs = parseFactor();
            if (op == '*') {
                result *= rhs;
            } else {
                if (rhs == 0) {
                    throw std::invalid_argument("Division by zero");
                }
                result /= rhs;
            }
        }
        return result;
    }

    int parseFactor() {
        if (input[position] == '(') {
            position++;
            int result = parseExpression();
            if (input[position] != ')') {
                throw std::invalid_argument("Unbalanced parentheses");
            }
            position++;
            return result;
        } else {
            int result = 0;
            while (position < input.length() && isdigit(input[position])) {
                result = result * 10 + (input[position] - '0');
                position++;
            }
            return result;
        }
    }

    const std::string input;
    std::size_t position;
};

int main() {
    std::string input;
    std::cout << "Enter an arithmetic expression: ";
    std::getline(std::cin, input);
    RecursiveDescentParser parser(input);
    try {
        int result = parser.parse();
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
