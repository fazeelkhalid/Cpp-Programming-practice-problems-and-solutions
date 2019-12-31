#include<iostream>

using namespace std;

int fraction (int numerator, int denomerator, int &answerNumerator, int &answerDenomerator) {

	if(numerator > 0 && denomerator > 0){
		int i;
		
		i = (numerator < denomerator)? numerator: denomerator;

		for(i; i > 1; i--) {
			if(numerator % i == 0 && denomerator % i == 0){
				break;
			}
		}
		answerNumerator = numerator / i;
		answerDenomerator = denomerator / i;
		
		return 1;
	}
	else
		return 0;
}

int main() {

	int numerator;
	int denomerator;
	int answerNumerator;
	int answerDenomerator;
	int itrate;

	cout<<"Enter Numerator";
	cin>>numerator;
	cout<<"Enter Denomerator";
	cin>> denomerator;

	itrate = fraction(numerator, denomerator,answerNumerator,answerDenomerator);

	if(!itrate) {
		cout<<"Pleace input non negative and non zero number\n";
		system("pause");
		return 0;
	}
	else {
		cout<<"Before reducing form : "<<numerator<<"/"<<denomerator<<endl;
		cout<<"After reducing form : "<<answerNumerator<<"/"<<answerDenomerator<<endl;
	}
	system("pause");

	return 0;

}
