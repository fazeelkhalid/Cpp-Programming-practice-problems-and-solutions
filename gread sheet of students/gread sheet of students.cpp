#include<iostream>
#include<stdlib.h>

using namespace std;

void computeWeightAge( float (&totalIndvidualMarks)[50], float cMarks[], float eMarks[], float pMarks[], float sMarks[], float dMarks[], int size,float &Marks) {
	Marks = 0;
	float weigthAge[5];
	int totalMarks[5];
	
	for(int i = 0; i < 85; i++) {
		cout<<"*";
	}
	cout<<endl;
	
	for(int i = 0; i < 5; i++) { // input total marks of all subjects
		cout<<"Enter the total marks of "<<i+1 <<" subject : ";
		cin>>totalMarks[i];
	} 
	
	for(int i = 0; i < 85; i++) {
		cout<<"*";
	}
	cout<<endl;
	
	for(int i = 0; i < 5; i++) { // input weightage of all subjects 
		cout<<"Enter weightage of " << i+1 <<" Subject : ";
		cin>> weigthAge[i];	
		Marks = Marks + weigthAge[i];
	}	
	for(int i = 0; i < 5; i++ ) { //total marks of students
		cMarks[i] = cMarks[i]/totalMarks[0]*weigthAge[0];
		eMarks[i] = (eMarks[i]/totalMarks[1]*weigthAge[1]);
		pMarks[i] = (pMarks[i]/totalMarks[2]*weigthAge[2]);
		sMarks[i] =(sMarks[i]/totalMarks[3]*weigthAge[3]);
		dMarks[i] = (dMarks[i]/totalMarks[4]*weigthAge[4]);
		totalIndvidualMarks[i] =cMarks[i] + eMarks[i] + pMarks[i] + sMarks[i] + dMarks[i];
	}
}

void swapNumber(float &firstNumber, float &secondNumber){

	float temp;
	
	temp = firstNumber;
	firstNumber = secondNumber;
	secondNumber = temp;

}
void swapNumber(int &firstNumber, int &secondNumber){

	int temp;
	
	temp = firstNumber;
	firstNumber = secondNumber;
	secondNumber = temp;

}

void selectionSort( int (&rNumber)[50],float (&totalIndvidualMarks)[50], float (&cMarks)[50], float (&eMarks)[50], float (&pMarks)[50], float (&sMarks)[50], float (&dMarks)[50], int size, char choose) {

	if(choose == 'A' || choose =='a') { // for Assending order
			
		for(int i = 0; i < size - 1; i++) {
			int small = rNumber[i];
			int Sindex;
			bool found = false;
			for(int j = i+1; j < size; j++) {
				if(small > rNumber[j] ) {
					small = rNumber[j];
					Sindex = j;
					found = true;
				}
			}
			if(found){
				swapNumber(totalIndvidualMarks[i],totalIndvidualMarks[Sindex]);
				swapNumber(eMarks[i],eMarks[Sindex]);
				swapNumber(pMarks[i],pMarks[Sindex]);
				swapNumber(sMarks[i],sMarks[Sindex]);
				swapNumber(dMarks[i],dMarks[Sindex]);
				swapNumber(rNumber[i],rNumber[Sindex]);
			}
		}
	}

	if(choose == 'D' || choose =='d') { // for Assending order
			
		for(int i = 0; i < size - 1; i++) {
			int small = rNumber[i];
			int Sindex;
			bool found = false;
			for(int j = i+1; j < size; j++) {
				if(small < rNumber[j] ) {
					small = rNumber[j];
					Sindex = j;
					found = true;
				}
			}
			if(found){
				swapNumber(totalIndvidualMarks[i],totalIndvidualMarks[Sindex]);
				swapNumber(eMarks[i],eMarks[Sindex]);
				swapNumber(pMarks[i],pMarks[Sindex]);
				swapNumber(sMarks[i],sMarks[Sindex]);
				swapNumber(dMarks[i],dMarks[Sindex]);
				swapNumber(rNumber[i],rNumber[Sindex]);
			}
		}
	}
}

void search(int (&rNumber)[50],float (&totalIndvidualMarks)[50],float (&cMarks)[50],float (&eMarks)[50],float (&pMarks)[50],float (&sMarks)[50],float (&dMarks)[50],int size,char choose,float Marks) {

	int studentSearch;
	int  end;
	int middle;
	
	bool present = false; 
	end = size - 1; // 0
	
	selectionSort(rNumber,totalIndvidualMarks, cMarks, eMarks, pMarks, sMarks, dMarks, size,choose);
	 
	cout<<"\nEnter roll number for searching : ";
	cin>>studentSearch;
	
	for(int starting = 0; starting <= end;) {
		middle = (starting+end) / 2;	
		if(studentSearch == rNumber[middle]) { // for list of student
			cout<<"\nStudent Roll Number : "<<rNumber[middle]<<endl;
			cout<<"Calculus Marks      : "<<cMarks[middle]<<endl;
			cout<<"Englishh Marks      : "<<eMarks[middle]<<endl;
			cout<<"Programming Marks   : "<<pMarks[middle]<<endl;
			cout<<"Social Marks        : "<<sMarks[middle]<<endl;
			cout<<"Data Sciences Marks : "<<dMarks[middle]<<endl;
			cout<<"Obtain Marks        : "<<totalIndvidualMarks[middle]<<endl;
			cout<<"Total Marks         : "<<Marks;
			present = true;	
			break;
		}	
		else if(studentSearch > rNumber[middle]){
			starting = middle+1;
		}
		else
			end = middle-1;
	}
	if(!present) {
		cout<<studentSearch<<" Not Present in system\n ";
	}
	
}

void list( int (&rNumber)[50],float (&totalIndvidualMarks)[50], float (&cMarks)[50], float (&eMarks)[50], float (&pMarks)[50], float (&sMarks)[50], float (&dMarks)[50], int size,float Marks) {
	cout<<endl;
	
	for(int i = 0; i < 85; i++) {
		cout<<"*";
	}
	
	for(int i = 0; i < size; i++) {
		cout<<endl;
		cout<<i+1<<")"<<endl;
		cout<<"Student Roll Number   : "<<rNumber[i]<<endl;
		cout<<"Calculus Marks        : "<<cMarks[i]<<endl;
		cout<<"Englishh Marks        : "<<eMarks[i]<<endl;
		cout<<"Programming Marks     : "<<pMarks[i]<<endl;
		cout<<"Social Marks 	      : "<<sMarks[i]<<endl;
		cout<<"Data Sciences Marks   : "<<dMarks[i]<<endl;
		cout<<"Obtain Marks          : "<<totalIndvidualMarks[i]<<endl;
		cout<<"Total Marks           : "<<Marks;
		cout<<endl;
		for(int i = 0; i < 85; i++) {
			cout<<"_";
		}
	}
	cout<<endl;
}

int menu( int (&rNumber)[50],float (&totalIndvidualMarks)[50], float (&cMarks)[50], float (&eMarks)[50], float (&pMarks)[50], float (&sMarks)[50], float (&dMarks)[50], int size,char choose, float Marks) {

	char operation = 'A'; // for starting loop
	while(operation != 'E' || operation != 'e') {
		
		cout<<endl;
		for(int i = 0; i < 85; i++) {
			cout<<"*";
		}
		
		cout<<"\nEnter operation \n\"S\" for just Sorting\n\"R\" for search \n\"L\" for display list\n\"C\" for clear screen\n\"E\" for Exit : ";
		cin>>operation;
		
		switch(operation) {
			case'S':{
				cout<<"\nEnter \n\"A\" for assending order\n\"D\" for deccending order : ";
				cin>>choose;
				if(choose == 'A' || choose == 'a' || choose == 'D' || choose == 'd') {
					selectionSort(rNumber,totalIndvidualMarks, cMarks, eMarks, pMarks, sMarks, dMarks, size,choose);
				break;
				}
				else {
					cout<<"\nPlease enter valid operation";
					break;
				}
				for(int i = 0; i < 85; i++) {
					cout<<"*";
				}
			}
			case's':{
				cout<<"\nEnter \n\"A\" for assending order\n\"D\" for deccending order : ";
				cin>>choose;
				if(choose == 'A' || choose == 'a' || choose == 'D' || choose == 'd') {
					selectionSort(rNumber,totalIndvidualMarks, cMarks, eMarks, pMarks, sMarks, dMarks, size,choose);
				break;
				}
				else {
					cout<<"\nPlease enter valid operation";
					break;
				}
				for(int i = 0; i < 85; i++) {
					cout<<"*";
				}
			}
			case'R':
				choose = 'a';
				search(rNumber,totalIndvidualMarks, cMarks, eMarks, pMarks, sMarks, dMarks, size,choose,Marks);
				break;
			case 'r':
				choose = 'a';
				search(rNumber,totalIndvidualMarks, cMarks, eMarks, pMarks, sMarks, dMarks, size,choose,Marks);
				break;
			case 'L':
				list(rNumber,totalIndvidualMarks, cMarks, eMarks, pMarks, sMarks, dMarks, size, Marks);
				break;
			case 'l':
				list(rNumber,totalIndvidualMarks, cMarks, eMarks, pMarks, sMarks, dMarks, size, Marks);
				break;
			case 'C':
				system("CLS");
				break;
			case 'c':
				system("CLS");
				break;
			case 'E':
				return 0;
			case 'e':
				return 0;
			
			default:{
				cout<<"Please enter correct operaion"<<endl;
			
			}
		}
	}
	return 0;
}

int main() {
	
	int rNumber[50]; // Roll Number
	float cMarks[50]; // calculus Marks
	float eMarks[50]; // English Marks
	float pMarks[50]; // Programming Fundamental Marks
	float sMarks[50]; // Social Marks
	float dMarks[50]; // Data Scences Marks
	float totalIndvidualMarks[50];
	char choose; // for assending or decending
	int size;
	float Marks; //for total marks;

	cout<<"Enter number of students : ";
	cin>>size; //size of array
	
	for(int i = 0; i < size; i++) { // loop for input roll numbers, subjects marks 
		cout<<"*********************************** Input Format *********************************** ";
		cout<<"\nRollNumber calculusMarks EnglishMarks ProgrammingMarks SocialMarks DataSciencesMarks"<<endl;
		cin>> rNumber[i]>> cMarks[i]>> eMarks[i]>> pMarks[i]>> sMarks[i]>> dMarks[i];
	
	}
	
	computeWeightAge(totalIndvidualMarks, cMarks, eMarks, pMarks, sMarks, dMarks, size,Marks);
	menu(rNumber,totalIndvidualMarks, cMarks, eMarks, pMarks, sMarks, dMarks, size,choose,Marks);
	
	return 0;		
}
