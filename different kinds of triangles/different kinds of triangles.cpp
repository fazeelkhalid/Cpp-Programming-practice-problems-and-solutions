#include<iostream>

using namespace std;

int main() {
	int rows;
	int space;
	int temp;
	int coloum = 1;
		
	cout<<"Please enter number of rows :";
	cin>>rows;
	temp = rows;
	
	for(int i = 0; i < rows; i++){
		for(int j = 0; j <= i; j++){
			cout<<"*";
		}
		cout<<endl;
	}
	
	/* QUESTIN 5 PART (B)*/
	
	cout<<endl<<endl<<endl;
	for(int i = 0;i < rows; i++){
		for(int k = rows; k > i; k--)
			cout<<" ";
			
		for(int j = 0;j <= i; j++){
			cout<<"*";
		}
		cout<<endl;	
	}
		/* QUESTIN 5 PART (c)*/
	cout<<endl<<endl<<endl;
	for(int i = 0; i < rows; i++){
		for(int j = rows; j  > i; j--){
			cout<<"*";
		}
		cout<<endl;
	}
		/* QUESTIN 5 PART (d)*/
	cout<<endl<<endl<<endl;	
	for(int i = rows; i > 0; i--) {
		for(int j = 0; j < i; j++) {
		cout<<"*";
		}
		cout<<endl;
		space = temp - 1;
		while(space < rows) {
			cout<<" ";
			space++;
		}
		temp--;		
	}
		/* QUESTIN 5 PART (e)*/
	cout<<endl<<endl<<endl;
		
	temp = rows;
	
	for(int i = 0; i < rows; i++) {
		
		space = temp - 1;
		while(space > 0) {
				cout<<" ";
				space--;
		}
		temp--;
		
		for(int k = 0; k < coloum ; k++) {
		cout<<"*";
		}
		
		coloum = coloum + 2;
		cout<<endl;
	}

	return 0;
}
