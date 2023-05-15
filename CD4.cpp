#include <iostream>
#include <regex>

int main() {
    std::string regex_str = "ab*";
    std::regex regex_pattern(regex_str);
    std::string input_str;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input_str);

    if (std::regex_match(input_str, regex_pattern)) {
        std::cout << "The string \"" << input_str << "\" matches the regular expression \"" << regex_str << "\"." << std::endl;
    } else {
        std::cout << "The string \"" << input_str << "\" does not match the regular expression \"" << regex_str << "\"." << std::endl;
    }

    return 0;
}
