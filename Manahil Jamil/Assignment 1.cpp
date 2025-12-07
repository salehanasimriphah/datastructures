#include<iostream>
using namespace std;
class Calculator{
	private:
	 int x,y;
	 static int operationCount;
	 //private parameterized constructor
	 Calculator(int a,int b){
	 	x=a;
	 	y=b;
	 }
	public:
	static Calculator createCalculator(int a, int b) 
		{
			return Calculator(a,b);
		}
		int sum(){
			operationCount++;
			return x+y;
		}
		int diff(){
			operationCount++;
			return x-y;
		}
		double quotient(){
			operationCount++;
			if(y==0){
				cout<<"Error:Division by zero!"<<endl;
				return 0;
			}
			return x/y;
		}
		double remainder(){
			operationCount++;
			if(y==0){
				cout<<"Error:Division by zero!"<<endl;
				return 0;
			}
			return x%y;
		}
		double percentage(){
			operationCount++;
			if(y==0){
				cout<<"Error:Division by zero!"<<endl;
				return 0;
			}
			return (x/y)*100;
		}
		static int getOperationCount(){
			return operationCount;
			}
		};
		
		//initiallize static variable
		int Calculator::operationCount=0;
		
		int main(){
			int a,b,choice;
			cout<<"Enter first number : "<<endl;
			cin>>a;
			cout<<"Enter second number : "<<endl;
			cin>>b;
			
			Calculator cal=Calculator::createCalculator(a,b);
			cout<<"****Choose An Operation****"<<endl;
			cout<<"1.Sum"<<endl;
			cout<<"2.Difference"<<endl;
			cout<<"3.Quotient"<<endl;
			cout<<"4.Remainder"<<endl;
			cout<<"5.Percentage"<<endl;
			cout<<"Enter your choice from the above "<<endl;
			cin>>choice;
			
			switch(choice){
				case 1:
					cout<<"Sum = "<<cal.sum()<<endl;
					break;
				case 2:
					cout<<"Difference = "<<cal.diff()<<endl;
					break;
				case 3:
					cout<<"Quotient = "<<cal.quotient()<<endl;
					break;
				case 4:
					cout<<"Remainder = "<<cal.remainder()<<endl;
					break;
				case 5:
					cout<<"Percentage = "<<cal.percentage()<<endl;
					break;
				defaul:
					cout<<"Invalid Choce "<<endl;
					
			}
			cout<<"Total Operation Performed :"<<Calculator::getOperationCount()<<endl;
			return 0;
		}
