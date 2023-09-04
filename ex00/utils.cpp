#include "includes/ScalarConverter.hpp"

std::string trim_white_space(const std::string& str) {
    size_t start = 0;
    size_t end = str.length() - 1;

    while (start <= end && std::isspace(str[start])) {
        ++start;
    }
    while (end >= start && std::isspace(str[end])) {
        --end;
    }
    return str.substr(start, end - start + 1);
}
