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
    static double percentage(int a, int b) {
        operationCount++;
        if (b == 0) {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
        return ((double)a / b) * 100;
    }
 static int getOperationCount() {
        return operationCount;
    }
};

int Calculator::operationCount = 0;
int main() {
    int choice,x,y;

    do {
        cout << "\n===== Calculator Menu =====" << endl;
        cout << "1. Sum" << endl;
        cout << "2. Difference" << endl;
        cout << "3. Quotient (Division)" << endl;
        cout << "4. Remainder" << endl;
        cout << "5. Percentage" << endl;
        cout << "6. Show total operations performed" << endl;
        cout << "0. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 5) {
            cout << "Enter first number: ";
            cin >> x;
            cout << "Enter second number: ";
            cin >> y;
        }

        switch (choice) {
            case 1:
                cout <<"Sum = "<< Calculator::sum(x,y)<<endl;
                break;
            case 2:
                cout <<"Difference = "<<Calculator::difference(x,y)<<endl;
                break;
            case 3:
                cout <<"Quotient = "<<Calculator::quotient(x,y)<<endl;
                break;
            case 4:
                cout <<"Remainder = "<<Calculator::remainder(x,y)<<endl;
                break;
            case 5:
                cout <<"Percentage = "<<Calculator::percentage(x,y)<<"%"<<endl;
                break;
            case 6:
                cout <<"Total operations performed: " 
                     << Calculator::getOperationCount()<<endl;
                break;
            case 0:
                cout <<"Exiting program..."<<endl;
                break;
            default:
                cout <<"Invalid choice! Try again."<<endl;
        }

    } while (choice != 0);

    return 0;
}
