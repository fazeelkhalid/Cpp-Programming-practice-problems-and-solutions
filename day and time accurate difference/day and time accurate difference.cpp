#include<iostream>

using namespace std;

int dayinMonth(int md,int y1) {
	int daymonth = 0;
	for(md; md > 0; md-- ) {
		
		if(md == 1 || md == 3|| md == 5|| md == 7|| md == 8 ||md == 10||md == 12) {
			daymonth += 31;
		}
		else if(md == 4 || md == 6 || md == 9|| md == 11){
			daymonth += 30;	
		}
		
		else if(md == 2 && y1 % 4 == 0) {
			daymonth += 29;
		}
		else
			daymonth += 28;
			
	
	}
	return daymonth;
}
int dayinYear(int yd,int y2,int y1) {
	int dayinYear = 0;
	for(int i = y2; i < y1; i++) {
		if(i % 4 == 0) {
			dayinYear +=366;
		}
		else
			dayinYear +=365;
	}
		
	return dayinYear;
}

int datediff(int y1, int m1,int d1, int y2, int m2, int d2, int &yd, int &md, int &dd ) {
		
	if(d1 - d2 < 0) {
		
		if(m1 == 1 || m1 == 3|| m1 == 5|| m1 == 7|| m1 == 8 ||md == 10||m1 == 12) {
			d1 += 31;
			m1 -= 1;
		}
		else if(m1 == 4 || m1 == 6 || m1 == 9|| m1 == 11){
			d1 +=30;
			m1 -= 1;
		}
		
		else if(m1 == 2 && y1 % 4 == 0) {
			d1 += 29;
			m1 -= 1;
		}
		else {
			d1 += 28;
			m1 -= 1;
		}
	}
	
	if(m1 - m2 < 0) {
		m1 += 12;
		y1 -= 1;
	}
	yd = y1 - y2;
	dd = d1- d2;
	md = m1 - m2;
	int result;

	result = dayinYear(yd,y2,y1) + dayinMonth(md,y1) + dd ;
	return result;
}

int timediff(int h1,int m1, int s1, int h2, int m2, int s2 ,int &hd, int &md, int &sd) {
	int result;
	
	if(s1 - s2 < 0) {
		s1 += 60;
		m1 -= 1;
	}
	if(m1 - m2 < 0) {
		m1 += 60;
		h1 -= 1;
	}
	hd = h1 - h2;
	md = m1 - m2;
	sd = s1 - s2;
	result = hd*3600 + md * 60 + sd;
	return result;
}

int main() {

	char operation;

	cout<<"Enter T for time difference and D for date difference :";
	cin>>operation;

	if(operation == 'D' || operation == 'd') {

		int year1;
		int year2;
		int month1;
		int month2; 
		int day1;
		int day2;
		char c;
		int result;
		int yd;
		int md;
		int dd;

		cout<<"****************** firstly input larger date ******************\n";
		cout<<"******************* Date format: DD/MM/YYYY *******************\n";
		cout<<"Enter first date : ";
		cin>>day1>>c>>month1>>c>>year1;
		if((day1 >= 0 && day1 <= 31) && (month1 >= 1 && month1 <= 12)) {
			cout<<"Enter second date : ";
			cin>>day2>>c>>month2>>c>>year2;
			
			if((day2 >= 0 && day2 <= 31) && (month2 >= 0 && month2 <= 12)) {
				result = datediff(year1, month1, day1, year2, month2, day2, yd, md, dd);
				cout<<"Total difference of date :"<<result;
					
				cout<<"\nYear difference :"<<yd;
				cout<<"\nMonth difference :"<<md;
				cout<<"\nDays difference :"<<dd<<endl;
			}
			else 
				cout<<"Enter valid date "<<endl;
		}
		else
			cout<<"Enter valid date "<<endl;
	}

	else if(operation == 'T' || operation == 't') {
	
		int hour1;
		int hour2;
		int min1;
		int min2;
		int sec1;
		int sec2;
		char c;
		int result;
		int hd;
		int md;
		int sd;

		cout<<"****************** firstly input larger time ******************\n";
		cout<<"********************* Date format HH:MM:SS ******************** \n";
		cout<<"Enter first time :";
		cin>>hour1>>c>>min1>>c>>sec1;
	
		if((hour1 >= 0 && hour1 <= 24) && (min1 >= 0 && min1 <= 60) && (sec1 >= 0 && sec1 <= 60)) {
		
			cout<<"Enter second time :";
			cin>>hour2>>c>>min2>>c>>sec2;
			
			if((hour2 >= 0 && hour2 <= 24) && (min2 >= 0 && min2 <= 60) && (sec2 >= 0 && sec2 <= 60)) {
				
				result = timediff(hour1, min1, sec1, hour2, min2, sec2, hd, md, sd);	
				cout<<"total time difference in second:"<<result;
				cout<<"\nhours difference :"<<hd;
				cout<<"\nminutes difference :"<<md;
				cout<<"\nsecond difference :"<<sd<<endl;
			}
			else
				cout<<"Enter valid time"<<endl;
		}
		else
			cout<<"Enter valid time"<<endl;
	}
	
	else
		cout<<"Please enter correct operation\n";
	
	system ("pause");
	
	return 0;
}
