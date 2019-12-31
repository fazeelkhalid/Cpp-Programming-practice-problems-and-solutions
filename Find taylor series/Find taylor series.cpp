#include<iostream>

using namespace std;

int main() {
	
	int x;
	int terms;
	float numerator = 0;
	float denominator = 0;
	float answer = 0;
	
	cout<<"enter the value of x :";
	cin>>x;
	cout<<"enter number of terms :";
	cin>>terms;
	
	for(int i = 0; i < terms; i++) {
		numerator *= x;
		denominator *= i;
		
		numerator = !numerator ? 1 : numerator;
		denominator = !denominator ? 1 : denominator;
		answer += numerator / denominator;
		
		if(x == 0)
			break;
	}
	cout<<answer;
	return 0;
}
