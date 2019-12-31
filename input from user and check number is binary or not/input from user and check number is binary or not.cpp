#include<iostream>

using namespace std;

int main() {

	int binary;
	int remainder;
	
	bool is_binary = true;
	
	cout<<"Please enter binary number";
	cin>>binary;
		if(binary >= 0){
				
			while(binary > 0) {
				remainder = binary % 10;
				binary /= 10;
				
				if(remainder%2 >= 1) {
					is_binary = false;
					binary = 0;
				}
			}
		
			if(is_binary) {
				cout<<"you entered a binary number";
			}
			else{
				cout<<"you enterd a decimal number";
			}
		}
		else{
			cout<<"you enterd a decimal number";
		}
		
	return 0;

}
