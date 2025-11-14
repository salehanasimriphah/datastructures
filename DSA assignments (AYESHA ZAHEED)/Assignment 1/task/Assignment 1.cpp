#include <iostream>
using namespace std;

class Calculator {
private:
    Calculator() {}
    static int operationCount;
public:
    static int sum(int a, int b) {
        operationCount++;
        return a + b;
    }
    static int difference(int a, int b) {
        operationCount++;
        return a - b;
    }
    static double quotient(int a, int b) {
        operationCount++;
        if (b == 0) {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
        return (double)a / b;
    }
    static int remainder(int a, int b) {
        operationCount++;
        if (b == 0) {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
        return a % b;
    }
    static double percentage(double a, double b) {
        operationCount++;
        if (b == 0) {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
        return (a / b) * 100;
    }
    static int getOperationCount() {
        return operationCount;
    }
};
int Calculator::operationCount = 0;

int main() {
    int choice;
    double num1, num2;
    bool running = true;
    while (running) {
        cout << "\n--- Calculator Menu ---\n";
        cout << "1. Sum\n";
        cout << "2. Difference\n";
        cout << "3. Quotient (Division)\n";
        cout << "4. Remainder\n";
        cout << "5. Percentage\n";
        cout << "6. Show total operations performed\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 5) {
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;
        }

        switch (choice) {
            case 1:
                cout << "Result: " << Calculator::sum(num1, num2) << endl;
                break;
            case 2:
                cout << "Result: " << Calculator::difference(num1, num2) << endl;
                break;
            case 3:
                cout << "Result: " << Calculator::quotient(num1, num2) << endl;
                break;
            case 4:
                cout << "Result: " << Calculator::remainder((int)num1, (int)num2) << endl;
                break;
            case 5:
                cout << "Result: " << Calculator::percentage(num1, num2) << "%" << endl;
                break;
            case 6:
                cout << "Total operations performed: " << Calculator::getOperationCount() << endl;
                break;
            case 7:
                running = false;
                cout << "Calculator Closed!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}

