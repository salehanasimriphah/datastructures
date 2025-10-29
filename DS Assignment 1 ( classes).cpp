#include <iostream>
using namespace std;

class Calculator {
public:
    static int OperationCount;

    static int sum(int a, int b);
    static int diff(int a, int b);
    static int rem(int a, int b);
    static int div(int a, int b);
    static int percentage(int a, int b);
    static int getOperationCount();

private:
    Calculator() {
        // private default constructor
    }
};

int Calculator::OperationCount = 0;

int Calculator::sum(int a, int b) {
    OperationCount++;
    return a + b;
}

int Calculator::diff(int a, int b) {
    OperationCount++;
    return a - b;
}

int Calculator::rem(int a, int b) {
    OperationCount++;
    if (b == 0) {
        cout << "Denominator cannot be zero" << endl;
        return 0;
    }
    return a % b;
}

int Calculator::div(int a, int b) {
    OperationCount++;
    if (b == 0) {
        cout << "Denominator cannot be zero" << endl;
        return 0;
    }
    return a / b;
}

int Calculator::percentage(int a, int b) {
    OperationCount++;
    if (b == 0) {
        cout << "Denominator cannot be zero" << endl;
        return 0;
    }
    return (a * 100) / b;
}

int Calculator::getOperationCount() {
    return OperationCount;
}

int main() {
    int choice, a, b;
  //applying do while loop to repeatedly ask user to enter to calculate untill 0
    do {
        cout << " Calculator Menu "<<endl;
        cout << "1. Sum"<<endl;
        cout << "2. Difference"<<endl;
        cout << "3. Division"<<endl;
        cout << "4. Remainder"<<endl;
        cout << "5. Percentage"<<endl;
        cout << "6. Show Total Operations"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 5) {
            cout << "Enter two numbers: ";
            cin >> a >> b;
        }

        switch (choice) {
            case 1:
                cout << "Sum: " << Calculator::sum(a, b) << endl;
                break;
            case 2:
                cout << "Difference: " << Calculator::diff(a, b) << endl;
                break;
            case 3:
                cout << "Quotient: " << Calculator::div(a, b) << endl;
                break;
            case 4:
                cout << "Remainder: " << Calculator::rem(a, b) << endl;
                break;
            case 5:
                cout << "Percentage: " << Calculator::percentage(a, b) << "%" << endl;
                break;
            case 6:
                cout << "Total operations performed: " << Calculator::getOperationCount() << endl;
                break;
            case 0:
                cout << "Exiting program"<<endl;
                break;
            default:
                cout << "Invalid choice! Please try again."<<endl;
        }

    } while (choice != 0);

    return 0;
}
