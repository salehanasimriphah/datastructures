#include<iostream>
using namespace std;

class Calculator{
	private:
		Calculator(){}   // private constructor means no object creation is allowed
	public:
		static int operationCount;    // static data member
		
		// static functions
		
		static int add(int a, int b){
			operationCount++;
			return a+b;
		}
		
		static int difference(int a, int b){
			operationCount++;
			return a-b;
		}
		
		static double quotient(double a, double b){
			operationCount++;
			if(b==0){
				cout<<"ERROR: Divison by zero." <<endl;
			}
			return a/b;
		}
		
		static int remainder(int a, int b){
			operationCount++;
			if(b==0){
				cout<<"ERROR: Divison by zero." <<endl;
				return 0;
			}
			return a%b;
		}
		
		static double percentage(double first_number, double second_number){
			operationCount++;
			if(second_number==0){
				cout<<"ERROR: Divison by zero." <<endl;
			}
			return (first_number / second_number) * 100;
		}

		static int getOperationCount(){
			return operationCount;
		}
};

int Calculator::operationCount = 0;    // initialization of static data member

int main(){
	int a = 20, b= 6;
	
	cout<<"Sum: " <<Calculator::add(a, b) <<endl;
    cout<<"Difference: "<<Calculator::difference(a, b) <<endl;
    cout<<"Quotient: "<<Calculator::quotient(a, b) <<endl;
    cout<<"Remainder: "<<Calculator::remainder(a, b) <<endl;
    cout<<"Percentage: "<<Calculator::percentage(30, 80) <<"%"<<endl;
    
    cout<<"\nTotal operations performed: "<<Calculator::getOperationCount() <<endl;
    
    return 0;
}
