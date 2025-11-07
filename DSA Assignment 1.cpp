#include<iostream>
using namespace std;
class Calculator{
	private:
		Calculator(){
			
		}
		static int operationCount;
	public:
		//sum
	static int sum(int a,int b){
		operationCount++;
		return a+b;
	}	
	//difference
	static int difference(int a,int b){
		operationCount++;
		return a-b;
	}
	//Quotient
	static double quotient(int a,int b){
		operationCount++;
		if(b==0){
			cout<<"Error: Division by zero!"<<endl;
			return 0;
		}
		return a/b;
	}
	//Remainder
	static int remainder(int a,int b){
		operationCount++;
		if(b==0){
			cout<<"Error: Division by zero!"<<endl;
			return 0;
		}
		return a % b;
	}
	//Percentage
	static double percentage(int a, int b){
		operationCount++;
		if(b==0){
			cout<<"Error: Division by zero!"<<endl;
			return 0;
		}
		return ( a / b ) * 100;
	}
	//Accessor Function
	static int getOperationCount(){
		return operationCount;
	}	
};
int Calculator::operationCount=0;
int main(){
	int a , b;
	cout<<"Enter First Number: ";
	cin>>a;
	cout<<endl;
	cout<<"Enter Second Number: ";
	cin>>b;
	cout<<endl;
	cout<<"Sum: "<<Calculator::sum(a,b)<<endl;
	cout<<"Difference: "<<Calculator::difference(a,b)<<endl;
	cout<<"Quotient: "<<Calculator::quotient(a,b)<<endl;
	cout<<"Remainder: "<<Calculator::remainder(a,b)<<endl;
	cout<<"Percentage: "<<Calculator::percentage(a,b)<<"%"<<endl;
	cout<<"\n Total Operations Performed: "<<Calculator::getOperationCount()<<endl;
	return 0;
}