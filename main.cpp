#include <iostream>
const char* find_dot_or_end(const char* str) {
    while (*str != '\0' && *str != '.') {
        str++;
    }
    return str;
}

int absolute(const char* number1_start, const char* number1_dot, const char* number2_start, const char* number2_dot) {

    size_t number1_len = number1_dot - number1_start;
    size_t number2_len = number2_dot - number2_start;
    
    if (number1_len < number2_len) return -1;
    if (number1_len > number2_len) return 1;
    
    while (number1_start < number1_dot) {
        if (*number1_start < *number2_start) return -1;
        if (*number1_start > *number2_start) return 1;
        number1_start++;
        number2_start++;
    }

    if (*number1_dot == '.') number1_dot++;
    if (*number2_dot == '.') number2_dot++;
    
    while (*number1_dot != '\0' && *number2_dot != '\0') {
        if (*number1_dot < *number2_dot) return -1;
        if (*number1_dot > *number2_dot) return 1;
        number1_dot++;
        number2_dot++;
    }

    if (*number1_dot != '\0') return 1;
    if (*number2_dot != '\0') return -1;
    
    return 0;
}

int main(int argc, char* argv[]) {

    const char* number1 = argv[1];
    const char* number2 = argv[2];
    
    bool number1_1s = false;
    bool number2_1s = false;
    
    if (*number1 == '-') { number1_1s = true; number1++; }
    else if (*number1 == '+') { number1++; }
    
    if (*number2 == '-') { number2_1s = true; number2++; }
    else if (*number2 == '+') { number2++; }

    if (*number1 == '0' && *(number1 + 1) == '\0' && *number2 == '0' && *(number2 + 1) == '\0') {
        std::cout << "equal" << std::endl;
        return 0;
    }
    
    if (number1_1s != number2_1s) {
        if (number1_1s) {
            std::cout << "less" << std::endl;
        } else {
            std::cout << "greater" << std::endl;
        }
        return 0;
    }

    const char* number1_dot = find_dot_or_end(number1);
    const char* number2_dot = find_dot_or_end(number2);

    int cmp = absolute(number1, number1_dot, number2, number2_dot);
    
    if (number1_1s) {
        cmp = -cmp;
    }
    
    if (cmp < 0) {
        std::cout << "less"<< std::endl;
    } else if (cmp > 0) {
        std::cout << "greater" << std::endl;
    } else {
        std::cout << "equal" << std::endl;
    }
    
    return 0;
}
