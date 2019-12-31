#include<iostream>

using namespace std;

int main() {
	
	int slope;
	int yIntercept;
	int y; 
	
	cout<<"Enter slope :";
	cin>>slope;
	cout<<"Enter Y intercept :";
	cin>>yIntercept;
	if(slope >= 0 && yIntercept >= 0) {
		
		for(int x = 5; x > 0; x--) {
			y = slope * x + yIntercept;
			
			for(int i = 0; i < y; i++) 
			cout<<" ";
			cout<<"*"<<endl;
		
		}
	}
	
	else {
		cout<<"Please input positive values";
	}
	return 0;
}
