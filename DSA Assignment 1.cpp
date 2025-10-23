#include<iostream>
using namespace std;

class Calculator{
	private:
		Calculator(){}
		
		static int operationCount;
		
		public:
	static int sum(int a, int b)		
	{
		operationCount++;
		return a+b;
	}
	static int difference(int a,int b)
	{
		operationCount++;
		return a-b;
	}
	static double quotient(int a,int b)
	{
		operationCount++;
		return a/(double)b;
	}
	static int remainder(int a,int b)
	{
		operationCount++;
		return a%b;
	}
	static double percentage(int a,int b)
	{
		
		operationCount++;
		return (a/b)*100;
	}
	
	static int getOperationCount(){
		return operationCount;
	}
};
	int Calculator::operationCount=0;

	int main(){
	cout<<"---CALCULATOR---"<<endl;
		cout<<"SUM:"<<Calculator::sum(30,40)<<endl;
			cout<<"DIFFERENCE:"<<Calculator::difference(50,40)<<endl;
				cout<<"QUOTIENT:"<<Calculator::quotient(30,40)<<endl;
					cout<<"REMAINDER:"<<Calculator::remainder(30,40)<<endl;
						cout<<"PERCENTAGE:"<<Calculator::percentage(10,10)<<"%"<<endl;
						
						cout<<"Operations Performed Total:"<<Calculator::getOperationCount()<<endl;
						return 0;
}