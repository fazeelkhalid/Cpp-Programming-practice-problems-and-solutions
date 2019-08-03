#include<iostream>

using namespace std;

int main() {
	char first_name[30];
	char second_name[30];
	char full_name[60];
	int size = 0;
	
	cout<<"Enter first name : ";
	cin>>first_name;
	
	cout<<"Enter second name : ";
	cin>>second_name;
	
    for(int i = 0; first_name[i] != '\0'; i++) 
    	size++;
    
	for(int i = 0; i < size; i++) {
		full_name[i] = first_name[i];
	}
	
	for(int i = size; i < 60; i++) {
		full_name[i] = second_name[i-size];
	}
	
	cout<<full_name;
		
	return 0;	 

}
