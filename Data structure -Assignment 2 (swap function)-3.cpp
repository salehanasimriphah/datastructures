#include<iostream>
using namespace std;

int main(){
	int swap(int a,int b){
	int temp= a;
	a=b;
	b=temp;
}
	
	int x, y;
	cout<<"enter the two values to swap: "<<endl;
	cin>>x>>y;
	cout<<"values before swaping: "<<"x: "<<x<<" y: "<<y<<endl;
	swap(x,y);
	cout<<"values after swaping: "<<"x: "<<x<<" y: "<<y;
	
}//this code is giving an error as funtion defintion is not allowed 