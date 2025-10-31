#include <iostream>
using namespace std;

class Calculator {
private:
    Calculator() {}
    static int operationCount;

public:
    static int sum(int a, int b) {
        operationCount++;
        return a+b;
    }

    static int difference(int a, int b) {
        operationCount++;
        return a-b;
    }

    static double quotient(int a, int b) {
        operationCount++;
        if (b==0) {
            cout<<"Error: Division by zero!"<<endl;
            return 0;
        }
        return (double)a/b;
    }

    static int remainder(int a, int b) {
        operationCount++;
        if (b==0) {
            cout << "Error: Division by zero!"<<endl;
            return 0;
        }
        return a%b;
    }
    static double percentage(double a, double b) {
        operationCount++;
        if (b==0) {
            cout<<"Error: Division by zero!" <<endl;
            return 0;
        }
        return (a/b)*100;
    }

    static int getOperationCount() {
        return operationCount;
    }
};

int Calculator::operationCount= 0;

int main() {
    cout<<"Sum: " << Calculator::sum(15,5)<<endl;
    cout<<"Difference: " <<Calculator::difference(15,5)<<endl;
    cout<<"Quotient: " <<Calculator::quotient(15,5)<<endl;
    cout<<"Remainder: " <<Calculator::remainder(15,5)<<endl;
    cout<<"Percentage: " <<Calculator::percentage(10,50)<<"%"<<endl;

    cout<<"\nTotal operations performed: " <<Calculator::getOperationCount()<<endl;

    return 0;
}

