#include <iostream>
#include <cmath>  // For pow()
using namespace std;

int main() {
    char operator_char;
    cout << "Enter operator (+, -, *, /, %, ^): ";
    cin >> operator_char;

    int x, y;
    cout << "Enter first number: ";
    cin >> x;

    cout << "Enter second number: ";
    cin >> y;

    switch (operator_char) {
        case '+':
            cout << "Result: " << x + y << endl;
            break;
        case '-':
            cout << "Result: " << x - y << endl;
            break;
        case '*':
            cout << "Result: " << x * y << endl;
            break;
        case '/':
            if (y != 0)
                cout << "Result: " << x / y << endl;
            else
                cout << "Error: Division by zero is not allowed." << endl;
            break;
        case '%':
            if (y != 0)
                cout << "Result: " << x % y << endl;
            else
                cout << "Error: Modulus by zero is not allowed." << endl;
            break;
        case '^':
            cout << "Result: " << pow(x, y) << endl;
            break;
        default:
            cout << "Invalid operator." << endl;
    }

    return 0;
}
