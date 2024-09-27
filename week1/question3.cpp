#include <iostream>
#include <string>

using namespace std;

struct action {
    string op;
    int (*func)(int, int);
};

int myadd(int x, int y) { return x + y;}
int mymin(int x, int y) { return x - y;}
int mymul(int x, int y) { return x * y;}
int mydiv(int x, int y) { return x / y;}

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
    action calc;
    calc.op = sign;
    if (calc.op == "+") calc.func = &myadd;
    else if (calc.op == "-") calc.func = &mymin;
    else if (calc.op == "*") calc.func = &mymul;
    else if (calc.op == "/") calc.func = &mydiv;

    return calc.func(a, b);
}

string many_infix_cal(const string& input) {
    int len = input.size();
    string operand = "", result = "";
    for (int i = 0; i <= len; i++) {
        if (input[i] != '\n' && input[i] != '\0') {
            operand += input[i];
        } else {
            result = result + to_string(infix_cal(operand)) + " ";
            operand = "";
        }
    }

    return result;
}

int main () {
    cout << many_infix_cal("10 + 2\n14 * 2\n102 - 10");
    return 0;
}