#include<iostream>

using namespace std;

float geoToDecimal (float d1, float m1,float s1,float d2,float m2, float s2,float &decimalLatitude) {

	if(d1 < 0) {
		decimalLatitude = d1 - (m1/60) - (s1/3600);
	}
	else{
		decimalLatitude = d1 + (m1/60) + (s1/3600);
	}

	if(d2 < 0) {
		return d2 - (m2/60) -(s2/3600);
	}
	else
		return d2 + (m2/60) + (s2/3600);
	 
}
 
int main() {

	float degree1;
	float min1;
	float sec1;
	float degree2;
	float min2;
	float sec2;
	float decimalLatitude;
	float decimalLongitude;
	char c;

	cout<<"******************** Format DD*MM'SS\" ********************\n";
	cout<<"Enter Degrees Minutes Seconds latitude : ";
	cin>>degree1>>c>>min1>>c>>sec1>>c;
	cout<<"Enter Degrees Minutes Seconds longitude : ";
	cin>>degree2>>c>>min2>>c>>sec2>>c;
	
	decimalLongitude = geoToDecimal(degree1, min1, sec1, degree2, min2, sec2, decimalLatitude);

	cout<<"Decimal latitude : "<<decimalLatitude<<endl;
	cout<<"Decimal longitude : "<<decimalLongitude<<endl;

	system("pause");

	return 0;
}
