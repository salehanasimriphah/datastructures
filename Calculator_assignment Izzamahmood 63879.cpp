#include <iostream>
using namespace std;

class Calculator {
private:
    Calculator() {}
    static int operationCount;
public:
    static float sum(float a,float b) {
        operationCount++;
        return a + b;
    }
    static float difference(float a,float b) {
        operationCount++;
        return a - b;
    }
    static float quotient(float a,float b) {
        operationCount++;
        if (b != 0)
            return a/b;
        else {
            cout<<"Error: Division by zero!"<<endl;
            return 0;
        }
    }
    static int remainder(int a,int b) {
        operationCount++;
        if (b != 0)
            return a%b;
        else {
            cout<<"Error: Division by zero!"<<endl;
            return 0;
        }
    }
    static float percentage(float a,float b) {
        operationCount++;
        if (b != 0)
            return (a/b) * 100;
        else {
            cout<<"Error: Division by zero!"<<endl;
            return 0;
        }
    }
      static int getOperationCount() {
        return operationCount;
    }
};
int Calculator::operationCount = 0;
int main() {
    float x = 20, y = 5;
    cout<<"Sum: "<<Calculator::sum(x, y)<<endl;
    cout<<"Difference: "<<Calculator::difference(x, y)<<endl;
    cout<<"Quotient: "<<Calculator::quotient(x, y)<<endl;
    cout<<"Remainder: "<<Calculator::remainder((int)x, (int)y)<<endl;
    cout<<"Percentage: "<<Calculator::percentage(x, y)<<"%"<<endl;
    cout<<"\nTotal operations performed: " 
         << Calculator::getOperationCount()<<endl;
    return 0;
}

