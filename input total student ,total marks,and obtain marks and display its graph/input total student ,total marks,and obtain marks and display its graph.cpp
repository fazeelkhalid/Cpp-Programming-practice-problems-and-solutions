#include<iostream>

using namespace std;

int main() {

	int totalStudent;
	int totalMarks;
	float obtainMarks;
	float percentage;
	int a = 0;
	int b= 0;
	int c= 0;
	int d= 0;
	int f= 0;
	
	cout<<"Enter total student :";
	cin>>totalStudent;
	cout<<"Enter total marks :";
	cin>>totalMarks;
			
	while(totalStudent > 0) {
		cout<<"obtain Marks :";
		cin>>obtainMarks;
		
		percentage = (obtainMarks / totalMarks) * 100;
		
		if(percentage >= 90) {
			a++;	
		}
		else if(percentage >= 75 && percentage < 90) {
			b++;	
		}
		else if(percentage >= 60 && percentage < 75 ) {
			c++;	
		}
		else if(percentage >= 50 && percentage < 60) {
			d++;	
		}
		else 
			f++;	
		
		totalStudent--;
	}
	cout<<endl<<"A: ";

	for(int i = a;a > 0; a--) {
	cout<<"*";
	}
	
	cout<<endl<<"B: ";

	for(int i = b;b > 0; b--) {
	cout<<"*";
	}
	
	cout<<endl<<"C: ";
		
	for(int i = c;c > 0; c--) {
	cout<<"*";
	}
	
	cout<<endl<<"D: ";
	
	for(int i = d;d > 0; d--) {
	cout<<"*";
	} 
	
	cout<<endl<<"F: ";
	
	for(int i = f;f > 0; f--) {
	cout<<"*";
	}
}
