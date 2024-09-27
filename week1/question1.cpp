#include <iostream>
#include <string>

using namespace std;

int infix_cal(const string& input) {
    int i = 0;
    string substr = "";

    // Handle first argument
    while (input[i] != ' ') {
        substr += input[i];
        i++;
    }
    int a = stoi(substr);
    i++;

    // Store the sign, wait for calculating
    char sign = input[i];
    i = i + 2;

    // Handle the second argument
    substr = "";
    while (input[i] != '\0') {
        substr += input[i];
        i++;
    }
    int b = stoi(substr);

    // Calculation
    float result = 0;
    switch (sign) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;
        default:
            break;
    }

    return result;
}

int main() {
    cout << infix_cal("10 - 2");
    return 0;
}