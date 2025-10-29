#include<iostream>
using namespace std;

int swap(int a,int b){
	int temp= a;
	a=b;
	b=temp;
}
int main(){
	int x, y;
	cout<<"enter the two values to swap: "<<endl;
	cin>>x>>y;
	cout<<"values before swaping: "<<"x: "<<x<<" y: "<<y<<endl;
	swap(x,y);
	cout<<"values after swaping: "<<"x: "<<x<<" y: "<<y;
	
}// by running this code, the values remain unswapped.