//create an array of size 6 and take six inputs from the user , also display these values by the user in c++
#include<iostream>
using namespace std;

int main(){
	int arr[6]; // array has declared here of size 6
	
	//applying loop to take input from user
	for(int i=0;i<6;i++){
		cout<<"Enter the value "<<i+1<<":"<<endl;
		cin>>arr[i];
	}
	
	//applying loop again to display the values entered by the user
	cout<<"The values you entered are :"<<endl;
	for(int i=0;i<6;i++){
		
		cout<<arr[i]<<endl;
}
}